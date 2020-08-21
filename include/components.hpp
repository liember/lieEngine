#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include <string>

/* components is 

- data ( just contain data )
- updaters ( update object every frame )
- modificators ( use data from out of object and updates in separately of update sycle )

*/
namespace Component
{

    namespace Data
    {
        class String : public std::string
        {
        };

        class Integer
        {
        private:
            long _value;

        public:
            long Get() { return _value; }
            explicit Integer(long value) { _value = value; }
            ~Integer();

            void Set(int n_val) { _value = n_val; }
            void operator+=(Integer i);
            void operator+=(long i);
            void operator-=(Integer i);
            void operator-=(long i);
            void operator*=(Integer i);
            void operator*=(long i);
            void operator/=(Integer i);
            void operator/=(long i);
        };

        class Floating
        {
        private:
            double _value;

        public:
            void Set(double n_val) { _value = n_val; }
            double Get() { return _value; }
            explicit Floating(double value) { _value = value; }
            ~Floating();

            void operator+=(Floating i);
            void operator+=(long i);
            void operator-=(Floating i);
            void operator-=(long i);
            void operator*=(Floating i);
            void operator*=(long i);
            void operator/=(Floating i);
            void operator/=(long i);
        };
    } // namespace Data

    namespace Updater
    {
        namespace
        {
            class Updateable
            {
            private:
            public:
                virtual void Update() = 0;
                Updateable();
                virtual ~Updateable() {}
            };

        } // namespace

        template <class T>
        class Speed : public Updateable
        {
        private:
            T _val;
            T &pos;

        public:
            void Set(T n_val) { _val }
            void Update() override { pos += _val.Get(); }
            Speed(T &pos_data, T val) : pos(pos_data), _val(val) {}
            ~Speed();
        };
        Speed<Data::Integer>;
        Speed<Data::Floating>;

    } // namespace Updater

    namespace Modificator
    {

    } // namespace Modificator

} // namespace Component
