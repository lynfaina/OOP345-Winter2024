// Review lvalue, xvalue, prvalue
#pragma once
#ifndef SDDS_TRACER_H
#define SDDS_TRACER_H
namespace sdds {
    constexpr char nl = '\n';
    // to able to print new lines
    // it can get printed using character
    class Tracer {
        bool m_trace{}; // on and off the message
        Tracer() = default; // nobody can instantiate it
        // put the default constructor in a private section
        // nobody can instantiate it but the Tracer itself
    public:
        static Tracer& instantiate(); // instantiate a Tracer
        // make it a singleton
        // there can only be one Tracer
        // static function belons to class, not the object
        Tracer(const Tracer&) = delete; // copy constructor
        Tracer& operator=(const Tracer&) = delete; // assignment operator
        Tracer& trace(bool value = true); // set by default to true
        const Tracer& operator<<(const char* message) const;
        const Tracer& operator<<(int val) const;
        const Tracer& operator<<(double val) const;
        const Tracer& operator<<(char ch) const;
    };
    extern Tracer& tracer; // to make available to everyone
    // tells that there is an instance called tracer in this file
    // and its not gonna be recreated by anyone else
    // tracer becomes only one instance of this class and
    // its a singleton, you cannot create two instances
    // its only one
}
#endif