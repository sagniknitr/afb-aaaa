
static const char _afb_description_v2_control[] =
    "{\"openapi\":\"3.0.0\",\"$schema\":\"http:iot.bzh/download/openapi/schem"
    "a-3.0/default-schema.json\",\"info\":{\"description\":\"\",\"title\":\"c"
    "ontroler\",\"version\":\"1.0\",\"x-binding-c-generator\":{\"api\":\"cont"
    "rol\",\"version\":2,\"prefix\":\"ctlapi_\",\"postfix\":\"\",\"start\":nu"
    "ll,\"onevent\":\"DispatchOneEvent\",\"init\":\"CtlBindingInit\",\"scope\""
    ":\"\",\"private\":false}},\"servers\":[{\"url\":\"ws://{host}:{port}/api"
    "/polctl\",\"description\":\"Unicens2 API.\",\"variables\":{\"host\":{\"d"
    "efault\":\"localhost\"},\"port\":{\"default\":\"1234\"}},\"x-afb-events\""
    ":[{\"$ref\":\"#/components/schemas/afb-event\"}]}],\"components\":{\"sch"
    "emas\":{\"afb-reply\":{\"$ref\":\"#/components/schemas/afb-reply-v2\"},\""
    "afb-event\":{\"$ref\":\"#/components/schemas/afb-event-v2\"},\"afb-reply"
    "-v2\":{\"title\":\"Generic response.\",\"type\":\"object\",\"required\":"
    "[\"jtype\",\"request\"],\"properties\":{\"jtype\":{\"type\":\"string\",\""
    "const\":\"afb-reply\"},\"request\":{\"type\":\"object\",\"required\":[\""
    "status\"],\"properties\":{\"status\":{\"type\":\"string\"},\"info\":{\"t"
    "ype\":\"string\"},\"token\":{\"type\":\"string\"},\"uuid\":{\"type\":\"s"
    "tring\"},\"reqid\":{\"type\":\"string\"}}},\"response\":{\"type\":\"obje"
    "ct\"}}},\"afb-event-v2\":{\"type\":\"object\",\"required\":[\"jtype\",\""
    "event\"],\"properties\":{\"jtype\":{\"type\":\"string\",\"const\":\"afb-"
    "event\"},\"event\":{\"type\":\"string\"},\"data\":{\"type\":\"object\"}}"
    "}},\"x-permissions\":{\"monitor\":{\"permission\":\"urn:AGL:permission:a"
    "udio:public:monitor\"},\"multimedia\":{\"permission\":\"urn:AGL:permissi"
    "on:audio:public:monitor\"},\"navigation\":{\"permission\":\"urn:AGL:perm"
    "ission:audio:public:monitor\"},\"emergency\":{\"permission\":\"urn:AGL:p"
    "ermission:audio:public:emergency\"}},\"responses\":{\"200\":{\"descripti"
    "on\":\"A complex object array response\",\"content\":{\"application/json"
    "\":{\"schema\":{\"$ref\":\"#/components/schemas/afb-reply\"}}}}}},\"path"
    "s\":{\"/monitor\":{\"description\":\"Subcribe Audio Agent Policy Control"
    " End\",\"get\":{\"x-permissions\":{\"$ref\":\"#/components/x-permissions"
    "/monitor\"},\"parameters\":[{\"in\":\"query\",\"name\":\"event_patern\","
    "\"required\":true,\"schema\":{\"type\":\"string\"}}],\"responses\":{\"20"
    "0\":{\"$ref\":\"#/components/responses/200\"}}}},\"/event_test\":{\"desc"
    "ription\":\"Pause Resume Test\",\"get\":{\"x-permissions\":{\"$ref\":\"#"
    "/components/x-permissions/monitor\"},\"parameters\":[{\"in\":\"query\",\""
    "name\":\"delay\",\"required\":false,\"schema\":{\"type\":\"interger\"}},"
    "{\"in\":\"query\",\"name\":\"count\",\"required\":false,\"schema\":{\"ty"
    "pe\":\"interger\"}}],\"responses\":{\"200\":{\"$ref\":\"#/components/res"
    "ponses/200\"}}}},\"/navigation\":{\"description\":\"Request Access to Na"
    "vigation Audio Channel.\",\"get\":{\"x-permissions\":{\"$ref\":\"#/compo"
    "nents/x-permissions/navigation\"},\"parameters\":[{\"in\":\"query\",\"na"
    "me\":\"zone\",\"required\":false,\"schema\":{\"type\":\"string\"}}],\"re"
    "sponses\":{\"200\":{\"$ref\":\"#/components/responses/200\"}}}},\"/multi"
    "media\":{\"description\":\"Request Access to Navigation Audio Channel.\""
    ",\"get\":{\"x-permissions\":{\"$ref\":\"#/components/x-permissions/navig"
    "ation\"},\"parameters\":[{\"in\":\"query\",\"name\":\"zone\",\"required\""
    ":false,\"schema\":{\"type\":\"string\"}}],\"responses\":{\"200\":{\"$ref"
    "\":\"#/components/responses/200\"}}}},\"/lua_docall\":{\"description\":\""
    "Execute LUA string script.\",\"get\":{\"x-permissions\":{\"$ref\":\"#/co"
    "mponents/x-permissions/navigation\"},\"parameters\":[{\"in\":\"query\",\""
    "name\":\"func\",\"required\":true,\"schema\":{\"type\":\"string\"}},{\"i"
    "n\":\"query\",\"name\":\"args\",\"required\":false,\"schema\":{\"type\":"
    "\"array\"}}],\"responses\":{\"200\":{\"$ref\":\"#/components/responses/2"
    "00\"}}}},\"/lua_dostring\":{\"description\":\"Execute LUA string script."
    "\",\"get\":{\"x-permissions\":{\"$ref\":\"#/components/x-permissions/nav"
    "igation\"},\"parameters\":[{\"in\":\"query\",\"required\":true,\"schema\""
    ":{\"type\":\"string\"}}],\"responses\":{\"200\":{\"$ref\":\"#/components"
    "/responses/200\"}}}},\"/lua_doscript\":{\"description\":\"Execute LUA st"
    "ring script.\",\"get\":{\"x-permissions\":{\"$ref\":\"#/components/x-per"
    "missions/navigation\"},\"parameters\":[{\"in\":\"query\",\"name\":\"file"
    "name\",\"required\":true,\"schema\":{\"type\":\"string\"}}],\"responses\""
    ":{\"200\":{\"$ref\":\"#/components/responses/200\"}}}}}}"
;

static const struct afb_auth _afb_auths_v2_control[] = {
	{ .type = afb_auth_Permission, .text = "urn:AGL:permission:audio:public:monitor" }
};

 void ctlapi_monitor(struct afb_req req);
 void ctlapi_event_test(struct afb_req req);
 void ctlapi_navigation(struct afb_req req);
 void ctlapi_multimedia(struct afb_req req);
 void ctlapi_lua_docall(struct afb_req req);
 void ctlapi_lua_dostring(struct afb_req req);
 void ctlapi_lua_doscript(struct afb_req req);

static const struct afb_verb_v2 _afb_verbs_v2_control[] = {
    {
        .verb = "monitor",
        .callback = ctlapi_monitor,
        .auth = &_afb_auths_v2_control[0],
        .info = NULL,
        .session = AFB_SESSION_NONE_V2
    },
    {
        .verb = "event_test",
        .callback = ctlapi_event_test,
        .auth = &_afb_auths_v2_control[0],
        .info = NULL,
        .session = AFB_SESSION_NONE_V2
    },
    {
        .verb = "navigation",
        .callback = ctlapi_navigation,
        .auth = &_afb_auths_v2_control[0],
        .info = NULL,
        .session = AFB_SESSION_NONE_V2
    },
    {
        .verb = "multimedia",
        .callback = ctlapi_multimedia,
        .auth = &_afb_auths_v2_control[0],
        .info = NULL,
        .session = AFB_SESSION_NONE_V2
    },
    {
        .verb = "lua_docall",
        .callback = ctlapi_lua_docall,
        .auth = &_afb_auths_v2_control[0],
        .info = NULL,
        .session = AFB_SESSION_NONE_V2
    },
    {
        .verb = "lua_dostring",
        .callback = ctlapi_lua_dostring,
        .auth = &_afb_auths_v2_control[0],
        .info = NULL,
        .session = AFB_SESSION_NONE_V2
    },
    {
        .verb = "lua_doscript",
        .callback = ctlapi_lua_doscript,
        .auth = &_afb_auths_v2_control[0],
        .info = NULL,
        .session = AFB_SESSION_NONE_V2
    },
    { .verb = NULL }
};

const struct afb_binding_v2 afbBindingV2 = {
    .api = "control",
    .specification = _afb_description_v2_control,
    .info = NULL,
    .verbs = _afb_verbs_v2_control,
    .preinit = NULL,
    .init = CtlBindingInit,
    .onevent = DispatchOneEvent,
    .noconcurrency = 0
};

