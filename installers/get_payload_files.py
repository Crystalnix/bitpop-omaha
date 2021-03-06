#!/usr/bin/python2.4
# Copyright 2009 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ========================================================================


def GetListOfPayloadFiles(prefix,
                          activex_filename,
                          bho_filename,
                          languages,
                          product_version):
  payload_files = [
      'HouseOfLifeUpdate.exe',
      'HouseOfLifeCrashHandler.exe',
      '%sholupdate.dll' % (prefix),
      '%s%s' % (prefix, activex_filename),  # One-Click DLL
      '%s%s' % (prefix, bho_filename),      # BHO proxy DLL
      'HouseOfLifeUpdateHelper.msi',
      ]

  for language in languages:
    payload_files += ['%sholupdateres_%s.dll' % (prefix, language)]

  return payload_files


