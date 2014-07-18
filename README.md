# FreeBSD private port for TrustedQSL

Based on `comms/trustedqsl` 2.0.2

## Status

17-JUL-2014: Reverted back to clang, re-incorporated shurd's patches on
XMLElement. So far the CLI tools seems to be running, but the GUI doesn't.

## Goals

* To build the CLI tools under `src/` (formerly tqsllib)
* To fix the bugs

## Bugs

* `tqsl` doesn't run after the updating message

## Changes

* Enable Cmake compilation options for building CLI tools under `src`
* Original patches included under `files/`

## CLI tools

* The CLI tools are built under `work/tqsl-2.0.2/src/`

## Some personal thoughts

* Checking duplicated in the tqsllib is superficial and not
  necessary. It even makes the signing speed slower. Sticking to the
  older version will be a better choice.

* C++ code is *VERY* difficult to understand and maintain.
