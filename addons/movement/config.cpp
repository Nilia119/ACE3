#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_common"};
        author[] = {"commy2","KoffeinFlummi","Tachii"};
        authorUrl = "https://github.com/commy2/";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFatigue.hpp"
//#include "CfgInventoryGlobalVariable.hpp"
#include "CfgMoves.hpp"

class ACE_Options {
    class GVAR(useImperial) {
        displayName = "$STR_ACE_Movement_UseImperial";
        default = 0;
    };
};
