# 4. Have a class to manage the config file

## Status

| Status   | Time                         |
| -------- | ---------------------------- |
| Accepted | 2024-09-27T15:50:20.8346293Z |

## Context

To read and write to and from the config file, we should have a class to
represent the current state of the file.

## Decision

We will create a `classes/configFile.cpp` class that will allow us to perform
CRUD operations upon the file.

## Consequences

- The initial state of the config file will have to be hardcoded,
- The class will have to be able to check if the config file is in a valid
  format
- The class will have to handle the creation and identification of RAD config
  files
