#!/bin/bash
# COMMENTS:
#   Handy script responsible for generation of the doxygen
# documentation, along with performing a check on whether
# the documentation is complete or not.
#
# USAGE:
#   genDoc.sh [-h]
#    -h        Print this help and exit.
#
# NOTE:
#  . It is assumed that the working directory is the top
#    of the project folder!
#


exeName=$0

function showHelp() {
    head -n 14 $exeName | sed -e 's/^#//' | sed -e 's/!\/bin\/bash//'
    exit 0
}

function runcmd() {
    local cmd=$1
    local tempLog="local_templog_doxy"
    echo "Running '$cmd'..."
    $cmd 2>&1 | tee $tempLog
    local status=0
    local warn=`grep -i ': warning: ' $tempLog`
    if [ "$warn" != "" ]; then
        echo "Documentation Error!!"
        grep -i ': warning: ' $tempLog
        echo "Fix these warnings, before continuing further..."
        status=1
    fi
    rm -f $tempLog
    echo
    return $status
}



# constants
TMPSRC=docs/src_temp
SRC=docs/src
CFGSRC=docs/arff-doxy-config

#TODO: VCS related initialization

# generate the documentation
runcmd "doxygen $CFGSRC"
status=$?

# save to the 'actual' locations
rm -rf $SRC
cp -r $TMPSRC $SRC

#TODO: VCS related updation

# clean up
rm -rf $TMPSRC
exit $status
