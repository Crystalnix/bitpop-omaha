// Copyright 2007-2009 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ========================================================================
//
// Kernel object names.
//
// TODO(omaha): rename MutexPrefix to ObjectPrefix
//              remove the similar names from constants.h

#ifndef OMAHA_COMMON_CONST_OBJECT_NAMES_H__
#define OMAHA_COMMON_CONST_OBJECT_NAMES_H__

#include <tchar.h>

namespace omaha {

// The prefix to use for global names in the win32 API's.
const TCHAR* const kGlobalPrefix = _T("Global\\G");

// Preserve legacy prefixes
const TCHAR* const kOmaha10GlobalPrefix = _T("Global\\");
const TCHAR* const kOmaha11GlobalPrefix = _T("Global\\G");
const TCHAR* const kOmaha11LocalPrefix = _T("Local\\L");

// Ensures that only one instance of machine or user Omaha is trying to setup at
// a time.
const TCHAR* const kSetupMutex = _T("{3cc54822-4f33-4ecf-9504-cac059b507dc}");

// Signals the process to exit. Currently the core and the worker listen to
// this event.
// This same name was used in Omaha 1 (post-i18n).
// TODO(omaha): Consider making all our processes listen to it. Maybe not the
// service, since the SCM controls the life time of the service.
const TCHAR* const kShutdownEvent =
    _T("{96243e77-0f80-48c2-a855-2872a8fe84e5}");

// Only used to shut down older (pre-i18n) Goopdates.
const TCHAR* const kEventLegacyQuietModeName =
    _T("Global\\%s{aa76e38e-ae4f-4712-86cd-a8d8c095911d}");

// The installed setup worker sends an event to the setup worker running from
// the temp directory to tell it to release the Setup Lock. The event's name
// is passed in this environment variable name.
const TCHAR* const kSetupCompleteEventEnvironmentVariableName =
    _T("HOUSEOFLIFE_UPDATE_SETUP_COMPLETE_EVENT_NAME");

// The installed setup worker sends an event to the setup worker running from
// the temp directory to tell it a UI has been displayed so it will not display
// a second UI on error. The event's name is passed in this environment variable
// name.
const TCHAR* const kUiDisplayedEventEnvironmentVariableName =
    _T("HOUSEOFLIFE_UPDATE_UI_DISPLAYED_EVENT_NAME");

// It enforces the Core only runs one instance per machine and one instance per
// each user session.
const TCHAR* const kCoreSingleInstance =
    _T("{cfccc27d-5a87-42ba-bd5c-bddf551bb194}");

// It enforces the Crash Handler only runs one instance per machine and one
// instance per each user session.
const TCHAR* const kCrashHandlerSingleInstance =
    _T("{26415116-5272-4ec9-bbfc-e021f20b3216");

// The mutex names for ensuring single instances of the worker.
// We allow only one instance of the update worker per session,
// and only one instance of the install worker per application.
// However since user omaha cannot create global names, the interactive
// worker is also per session. I.e. two users can simultaneously install
// the same application.
const TCHAR* const kSingleupdateWorker =
    _T("{6ce8c0cd-e042-401a-a3cc-7c3ea361aba3}");

// Mutex name for ensuring only one installer for an app is running in a
// session. The %s is replaced with the application guid.
const TCHAR* const kSingleInstallWorker =
    _T("%s-{60e0d1a3-d292-49f2-9e3f-058e13df9270}");

// Base name of job object for Setup phase 1 processes except self updates.
// These may not be running as Local System for machine installs like
// self-updates do.
const TCHAR* const kSetupPhase1NonSelfUpdateJobObject =
    _T("{cc40c309-e1c4-4df6-abb5-dec98bda8801}");

// Base name of job object for interactive install processes except /install.
const TCHAR* const kAppInstallJobObject =
    _T("{852b862b-0dda-4663-8e61-5ae329705531}");

// Base name of job object for silent processes that are okay to kill.
const TCHAR* const kSilentJobObject =
    _T("{dd254daa-9f4e-44ee-a955-a08f743f0638}");

// Base name of job object for silent processes that should not be killed.
const TCHAR* const kSilentDoNotKillJobObject =
    _T("{af774fe1-a54a-475e-aa45-259826fb9418}");

// The global lock to ensure that a single app is being installed for this
// user/machine at a given time.
const TCHAR* const kInstallManagerSerializer =
    _T("{e479ca0d-b578-4573-82b2-bcb09a0422d7}");

// Serializes access to metrics stores, machine and user, respectively.
const TCHAR* const kMetricsSerializer =
    _T("{2eb0e506-50f6-4736-bf86-d8d777392ab5}");

// Serializes access to the global network configuration, such as the CUP keys.
const TCHAR* const kNetworkConfigLock =
    _T("{d9356416-fcad-490f-8538-bc991c25db9c}");

// The name of the shared memory object containing the serialized COM
// interface pointer exposed by the machine core.
const TCHAR* const kGoogleUpdateCoreSharedMemoryName =
    _T("Global\\HouseOfLifeUpdateCore");

}  // namespace omaha

#endif  // OMAHA_COMMON_CONST_OBJECT_NAMES_H__

