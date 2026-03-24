#ifndef SPEAKER_H
#define SPEAKER_H

namespace dsw
{
    class Speaker
    {
        public:
        int volume;
        bool mute;

        Speaker() : volume(20), mute(false) {}
        Speaker (const Speaker& obj) : volume(obj.volume), mute(obj.mute) {}

        Speaker& operator= (const Speaker& rhs)
        {
            if (this != &rhs)
            {
                volume = rhs.volume;
                mute = rhs.mute;
            }
            return *this;
        }
        ~Speaker() {}
    };
}

#endif