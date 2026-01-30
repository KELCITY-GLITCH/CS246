#!/usr/bin/env zsh
set -euo pipefail

repo_dir="${1:-.}"
msg_default="Update $(date +'%Y-%m-%d %H:%M:%S')"
commit_msg="${2:-$msg_default}"

cd "$repo_dir"

if ! git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
  echo "Not a git repository: $repo_dir"
  exit 1
fi

if [ -e .git/MERGE_HEAD ]; then
  echo "A merge is in progress. Finish it before syncing."
  exit 1
fi

if git rev-parse --abbrev-ref "@{upstream}" >/dev/null 2>&1; then
  git pull --rebase --autostash
else
  echo "No upstream tracked for current branch; will set on first push."
fi

git add -A

if ! git diff --cached --quiet; then
  git commit -m "$commit_msg"
else
  echo "No changes to commit."
fi

branch=$(git rev-parse --abbrev-ref HEAD)
if git rev-parse --abbrev-ref "$branch@{upstream}" >/dev/null 2>&1; then
  git push
else
  git push -u origin "$branch"
fi

echo "Sync complete for branch: $branch"