--[[
  Copyright (C) 2016 "IoT.bzh"
  Author Fulup Ar Foll <fulup@iot.bzh>
 
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
 
    http://www.apache.org/licenses/LICENSE-2.0
 
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  
 
  Provide sample LUA routines to be used with AGL control "lua_docall" API
--]]

-- global counter to keep track of calls
count=0

-- Adjust Volume function of vehicle speed
function Oncall_Helloworld (request, args)
  count=count+1

  AFB:notice("LUA OnCall Helloworld count=%d args=%s", count, args);
  AFB:success (request, {"count"=count}) 
end

function Test_Async_CB (request, result, context) 

   AFB:notice ("Test_Async_CB result=%s context=%s", result, context)
   AFB:success (request, {"response"=result, "context"=context})
end

function Test_Call_Async (request, args) 
   local context={
     "value1"="abcd",
     "value2"=1234
   }

   AFB:notice ("Test_Call_Async args=%s", args)
   AFB:service("alsacore","ping", args, "Test_Async_CB", context)
end

function Test_Call_Sync (request, args) 

    AFB:notice ("Test_Call_Sync args=%s", args)
    local err, response= AFB:service_sync ("alsacore","ping", args)
    if (err) then
        AFB:fail ("AFB:service_call_sync fail");
    else
        AFB:success (request, response)
    end
end

-- create a new event name
function Test_Event_Make (request, args) 

    AFB:notice ("Test_Event_Make args=%s", args)
    local err eventFD AFB:event (args["evtname"])    
    if (err) then
        AFB:fail ("AFB:Test_Event_Make fail event=%s", args["evtname"]);
    else
        AFB:success (request, {})
    end

    local evtData = {
        val1="My 1st private Event",
        val2=5678
    }

    AFB:notify (eventFD, evtData)
end

-- send an event on default binder event
function Test_Event_Notify (request, args) 

    AFB:notice ("Test_Event_Notify args=%s", args)
    local err AFB:notify (args)    
    if (err) then
        AFB:fail ("AFB:Test_Event_Make fail event=%s", args["evtname"]);
    else
        AFB:success (request, {})
    end
end
