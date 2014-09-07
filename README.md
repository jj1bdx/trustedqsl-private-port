# FreeBSD private port for TrustedQSL

Based on `comms/trustedqsl` 2.0.3

## Status

7-SEP-2014: 2.0.3\_1 merged as port r365611.

19-JUL-2014: 2.0.3 merged as port r362230.

18-JUL-2014: More fix from shurd. GUI fixed by enforcing `shared_ptr` use
on `tqsl_setCertificateStatus()` in `openssl_cert.cpp`
(commit 3b4c8aee8dc2dddaf85315af3a37bbebd2fac13b)

17-JUL-2014: Reverted back to clang, re-incorporated shurd's patches on
XMLElement. So far the CLI tools seems to be running, but the GUI doesn't.

## Goals

* To build the CLI tools under `src/` (formerly tqsllib)
* To fix the bugs

## Bugs

* SOLVED: `tqsl` doesn't run after the updating message

## Some personal thoughts

* Checking duplicated in the tqsllib is superficial and not
  necessary. It even makes the signing speed slower. Sticking to the
  older version will be a better choice.

* C++ code is *VERY* difficult to understand and maintain.
