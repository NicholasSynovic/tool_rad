#!/bin/bash

echo "Setting up repository"

pre-commit install
cmake .
