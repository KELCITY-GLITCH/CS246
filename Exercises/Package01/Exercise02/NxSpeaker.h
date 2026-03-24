#ifndef NXSPEAKER_H
#define NXSPEAKER_H

namespace dsw
{
    class NxSpeaker
    {
        private:
        int volume;
        bool mute;

        public:
        NxSpeaker() :volume(20), mute(false) {}

        NxSpeaker(const NxSpeaker& obj) : volume(obj.volume), mute(obj.mute) {}

        NxSpeaker& operator= (const NxSpeaker& rhs)
        {
            if (this != &rhs)
            {
                volume = rhs.volume;
                mute = rhs.mute;
            }
            return *this;
        }

        ~NxSpeaker() {}

        int getVolume() const {return volume;}
        bool getMute () const {return mute;}

        void setVolume(int v)
        {
            if (v >= 0 && v <= 100)
            {
                volume = v;
            }
        }

        void setMute(bool m)
        {
            mute = m;
        }
    };
}

#endif