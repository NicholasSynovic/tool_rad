# `rad` - Record Architecture Decisions

> A small tool to help you record your architecture decisions

## Table of Contents

- [`rad` - Record Architecture Decisions](#rad---record-architecture-decisions)
  - [Table of Contents](#table-of-contents)
  - [About](#about)
  - [How To Install](#how-to-install)
  - [How To Configure `rad`](#how-to-configure-rad)
  - [ADR Formats](#adr-formats)

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

## How To Configure `rad`

You can initialize `rad` with:

```shell
rad init
```

This will create a `.rad.json` file in the current directory.

The `.rad.json` file is intentionally sparse. The following options can be
configured in the file:

- `adr_directory`: The *relative* path to store ADRs.
  - Default: `docs/adr`
- `adr_format`: The format of the ADRs.
  - Default: `nygard`.
    - See [ADR Formats](#adr-formats) for a list of availible formats

## ADR Formats

The following ADR formats are supported:

- `edgex`: EdgeX
- `business`: Business
- `madr`: Markdown ADR (MADR)
- `tyree`: Tyree
- `planguage`: Planguage
- `alexandrian`: Alexandrian
- `nygard`: Nygard
