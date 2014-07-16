# FreeBSD private port for TrustedQSL

`comms/trustedqsl` 2.0.2

## Bugs

* Unable to link `tqsl`
* Usage of C++ `std::shared_ptr` looks broken: related patches excluded

## Changes

* Enable `USE_GCC`
* Enable Cmake compilation options for building CLI tools under `src`
* Original patches included under `files/`
* Patches excludes are under `files/NOT-APPLIED`

## CLI tools

* The CLI tools are built under `work/tqsl-2.0.2/src/`

