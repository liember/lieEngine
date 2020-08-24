#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <chrono>
#include <memory>

namespace Core
{
    namespace Eventor
    {
        class Exception : virtual public std::exception
        {

        protected:
            const std::string error_message;

        public:
            explicit Exception(const std::string &msg) : error_message(msg)
            {
            }
            virtual ~Exception() throw() {}

            virtual const char *what() const throw()
            {
                return error_message.c_str();
            }
        };

        class Timer
        {
        private:
            double creationTime;
            double criticalTime;

        public:
            Timer();
            ~Timer();

            double GetCurrentTime();
            // returns true if went more time than <dealy>, count from <source>
            bool Timeout(double source, double delay);
        };
    } // namespace Eventor

    class Object
    {
    public:
        int draw_id;
        bool isLife;
        bool update;
        bool draw;
        bool update_prior; // high - true / low - false

        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual ~Object(){};
    };

    class ObjectsManager
    {
    private:
    public:
        ObjectsManager();
        ~ObjectsManager();
    };

    class MinimalCore
    {
    protected:
        // list of objects what may will rendered
        std::unique_ptr<std::vector<Object *>> draw;

        // contains while updates update list (every frame)
        std::vector<Object *> objects;

    private:
        int max_update_prior; // set automaticly
        int cur_update;       // from 0 up to max_update_prior

        bool runstatus;

    public:
        // returns elements what marked as drawable
        std::unique_ptr<std::vector<Object *>> GetDrawList();

        MinimalCore()
        {
            runstatus = true;
        }

        // update objects and fill draw list
        void Update();

        // delete all elements in update list
        void clean();

        // add element to update list
        void Add(Object *p);

        bool running() { return runstatus; }
    };

} // namespace Core
