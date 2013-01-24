#!/bin/bash

VIEWER=okular
LATEX=latex

$LATEX Approx.tex > /dev/null
sleep 1;
$VIEWER Approx.dvi
