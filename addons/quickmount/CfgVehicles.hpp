class CfgVehicles {
    class ACE_Module;
    class GVAR(module): ACE_Module {
        author = ECSTRING(common,ACETeam);
        category = "ACE";
        displayName = CSTRING(Category);
        function = QFUNC(moduleInit);
        scope = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        icon = "a3\ui_f\data\IGUI\Cfg\Actions\Obsolete\ui_action_getin_ca.paa";
        class Arguments {
            class enabled {
                displayName = ECSTRING(common,Enabled);
                description = CSTRING(KeybindDescription);
                typeName = "BOOL";
                defaultValue = 1;
            };
            class distance {
                displayName = CSTRING(Distance);
                description = CSTRING(DistanceDescription);
                typeName = "NUMBER";
                defaultValue = DEFAULT_DISTANCE;
            };
            class speed {
                displayName = CSTRING(Speed);
                description = CSTRING(SpeedDescription);
                typeName = "NUMBER";
                defaultValue = DEFAULT_SPEED;
            };
        };
        class ModuleDescription {
            description = CSTRING(KeybindDescription);
        };
    };

#define GETIN_ACTIONS \
        class ACE_Actions { \
            class ACE_MainActions { \
                class GVAR(GetIn) { \
                    displayName = "$STR_rscMenu.hppRscGroupRootMenu_Items_GetIn1"; \
                    condition = QUOTE(call DFUNC(canShowFreeSeats)); \
                    statement = QUOTE(call DFUNC(getInNearest)); \
                    exceptions[] = {"isNotSwimming"}; \
                    insertChildren = QUOTE((_this select 2) param [ARR_2(0,[])]); \
                }; \
            }; \
        }; \
        class ACE_SelfActions { \
            class GVAR(ChangeSeat) { \
                displayName = CSTRING(ChangeSeat); \
                icon = QPATHTOF(UI\Seats_ca.paa); \
                condition = QUOTE(call DFUNC(canShowFreeSeats)); \
                insertChildren = QUOTE(call DFUNC(addFreeSeatsActions)); \
            }; \
        }

    class LandVehicle;
    class Car: LandVehicle {
        GETIN_ACTIONS;
    };
    class Motorcycle: LandVehicle {
        GETIN_ACTIONS;
    };
    class StaticWeapon: LandVehicle {
        GETIN_ACTIONS;
    };
    class Tank: LandVehicle {
        GETIN_ACTIONS;
    };
    class Air;
    class Helicopter: Air {
        GETIN_ACTIONS;
    };
    class Plane: Air {
        GETIN_ACTIONS;
    };
    class Ship;
    class Ship_F: Ship {
        GETIN_ACTIONS;
    };

};
