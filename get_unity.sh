#!/bin/bash

DIR="unity"
REPOS="https://github.com/ThrowTheSwitch/Unity.git"
BRANCH="master"
CHECKOUT_DIR="src"

mkdir -p $DIR
if [ -d "$DIR" ]; then
  cd $DIR
  git init
  git remote add -f origin $REPOS
  git fetch --all
  git config core.sparseCheckout true
  if [ -f .git/info/sparse-checkout]; then
    rm .git/info/sparse-checkout
  fi
  echo $CHECKOUT_DIR >> .git/info/sparse-checkout
  git checkout $BRANCH
  git merge --ff-only origin/$BRANCH
fi