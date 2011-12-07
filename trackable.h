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

#ifndef _TRACKABLE_H_
#define _TRACKABLE_H_

#include <boost/shared_ptr.hpp>

class Trackable;    // forward definition
typedef boost::shared_ptr<Trackable>        SharedTrackablePtr;


/**
* This class is the base class for any object which needs to be created by
* the RsrcMngr.
*
* @note This class may throw exceptions.
*/
class Trackable
{
public:
    /**
     * All unique objects which are trackable and thus are allowed to be
     * created and destroyed by RsrcMngr:: must be listed here.
     */
    typedef enum {
        OBJ_MEMBUFFER,          // C++ obj represents kernel or user space mem
        OBJ_ACQ,                // C++ obj represents an ACQ within dnvme
        OBJ_ASQ,                // C++ obj represents an ASQ within dnvme
        OBJ_IOCQ,               // C++ obj represents an IOCQ within dnvme
        OBJ_IOSQ,               // C++ obj represents an IOSQ within dnvme
        OBJ_IDENTIFY,           // Admin cmd set identify cmd
        OBJ_CREATEIOCQ,         // Admin cmd set create IOCQ cmd
        OBJ_CREATEIOSQ,         // Admin cmd set create IOSQ cmd
        OBJ_DELETEIOCQ,         // Admin cmd set delete IOCQ cmd
        OBJ_DELETEIOSQ,         // Admin cmd set delete IOSQ cmd

        OBJTYPE_FENCE           // always must be last element
    } ObjType;

    /// Used to compare for NULL pointers being returned by allocations
    static SharedTrackablePtr NullTrackablePtr;


    /**
     * Those whom derive from this must register what type of object they
     * are to allow the RsrcMngr to control creation and destruction of
     * that object.
     * @param objBeingCreated Pass the type of object this child class is
     */
    Trackable(ObjType objBeingCreated);
    virtual ~Trackable();

    ObjType GetObjType() { return mObjType; }


private:
    Trackable() {}

    ObjType mObjType;
};


#endif