###########################################################################
# Copyright 2015, 2016, 2017 IoT.bzh
#
# author: Fulup Ar Foll <fulup@iot.bzh>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
###########################################################################

# Project Info
# ------------------
  set(NAME audio-bindings)
  set(VERSION "1.0")
  set(PRETTY_NAME "Audio Bindings")
  set(DESCRIPTION "Expose ALSA Sound Low+High Level APIs through AGL Framework")
  set(URL "https://github.com/iotbzh/auto-bindings")

# Compilation Mode (DEBUG, RELEASE)
# ----------------------------------
  setc(CMAKE_BUILD_TYPE "DEBUG")

# PKG_CONFIG required packages
# -----------------------------
  set (PKG_REQUIRED_LIST 
    alsa
    json-c
    afb-daemon
  )

# Static constante definition
# -----------------------------
  add_compile_options(-DMAX_SND_CARD=16)
  add_compile_options(-DCONTROL_CDEV_RX="/dev/inic-usb-crx")

# Optional dependencies order
# ---------------------------
  #set(EXTRA_DEPENDENCY_ORDER target1 target2 ...)

# Optional Extra global include path
# ------------------------------------
  #set(EXTRA_INCLUDE_DIRS incdir1 incdir2 ...)

# Optional extra libraries
# -------------------------
  # set(EXTRA_LINK_LIBRARIES lib1 lib2 ... )

# Install default destination 
# --------------------------------
  set(binding_install_dir ${CMAKE_INSTALL_FULL_LIBDIR}/${PROJECT_NAME})

# Print a helper message when every thing is finished
# ----------------------------------------------------
  setc(CLOSING_MESSAGE "Test with: afb-daemon --ldpaths=. --port=1234 --roothttp=../htdocs --tracereq=common --token="" --verbose")

