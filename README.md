PerSt
=======

Persistent storage pile used for storing key/value pairs
on different underlying objects.

The pile provides an interface in the form of [perst] class
and a number of providers:
- registry - based on QSettings and registry
- config - based on QSettings and file system
- xml - based on an XML file

Instantiating and general management is performed through
[perstFactory] class and it also allows custom
providers to be added.

Usage
-----

Initialization and termination needs to be done once per
application:

    PerStFactory::init ();
    // ...
    PerStFactory::end ();

To create a new file-based instance with QSettings back-end
and read the content if the file "config.ini" exists use:

    PerSt * result = PerStFactory::create (
        "config",
        "config.ini");
    result->beginGroup ("general");
    int port = result->valueInt ("in_port");
    ++port;
    result->setValue ("out_port", port);
    result->endGroup ("general");
    // ...
    delete result;

Dependencies
------------

- Qt (either 4.X or 5.X) is optional (the pile
uses QString used for strings but it may also use std::string);
- UserMsg pile

[perst]: @ref PerSt "PerSt"
[perstFactory]: @ref PerStFactory "PerStFactory"
