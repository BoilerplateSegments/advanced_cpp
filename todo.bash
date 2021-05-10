#!/bin/bash

set -e #exit when cmd fail

install_ack() {
  if [ -f /etc/os-release ]; then
    . /etc/os-release
    case "$ID_LIKE" in
    "ubuntu debian")
      sudo apt install silversearcher-ag
      ;;
    "rhel fedora")
      sudo dnf install the_silver_searcher
      ;;
    "opensuse suse")
      sudo zypper in the_silver_searcher
      ;;
    "arch")
      pacman -S the_silver_searcher
      ;;
    *)
      echo "Unable to determine distro"
      cat /etc/os-release
      echo "=========================="
      exit 1
      ;;
    esac
  else
    echo "Unable to detect distro name"
    exit 1
  fi
}

if ! command -v ack &>/dev/null; then
  echo "ack auto installing..."
  install_ack
fi

ag --ignore "todo.bash" "TODO|FIXME|SHIT"
