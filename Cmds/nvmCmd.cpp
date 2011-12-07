/*
 * Copyright (c) 2011, Intel Corporation.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "nvmCmd.h"


NVMCmd::NVMCmd() :
    Cmd(0, Trackable::OBJTYPE_FENCE)
{
    // This constructor will throw
}


NVMCmd::NVMCmd(int fd, Trackable::ObjType objBeingCreated) :
    Cmd(fd, objBeingCreated)
{
}


NVMCmd::~NVMCmd()
{
}


void
NVMCmd::Init(uint8_t opcode, DataDir dataDir)
{
    Cmd::Init(CMD_NVM, opcode, dataDir, 64);
}