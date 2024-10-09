# RAD - Record Architecture Decisions

> A small tool to help you record your architecture decisions

## Table of Contents

- [RAD - Record Architecture Decisions](#rad---record-architecture-decisions)
  - [Table of Contents](#table-of-contents)
  - [About](#about)
  - [How To Install](#how-to-install)

## About

This project is a continuation of the [`talo`](https://github.com/canpolat/talo)
project in the sense to provide a single tool to manage Architecture Decision
Reports (ADRs) within projects. Unlike `talo`, `rad` is meant to soley focus on
ADRs and limit user configuration in the spirit of
[`black`](https://github.com/psf/black). Additionally, this tool takes
inspiration from [`git`](https://git-scm.com) to allow you to record ADRs
anywhere within the project instead of just in the project's root directory.

## How To Install

The following instructions allow you to build `rad` locally:

```shell
git clone https://github.com/NicholasSynovic/tool_rad
cd tool_rad
cmake .
make
cp ./bin/rad ~/.local/bin/rad
```
