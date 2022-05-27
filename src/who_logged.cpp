#include "loader.h"
#include "Configuration/Config.h"
#include "Player.h"
#include "Creature.h"
#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Define.h"
#include "GossipDef.h"

class WhoLoggedAnnounce : public PlayerScript
{
public:
    WhoLoggedAnnounce() : PlayerScript("WhoLoggedAnnounce") { }

    void OnLogin(Player* player)
    {
        std::string playerIP = player->GetSession()->GetRemoteAddress();
        std::string playerName = player->GetName();
        uint32 pAccountID = player->GetSession()->GetAccountId();
        uint32 pLevel = player->getLevel();
        std::string pClass;
        std::ostringstream message;

        if (!sConfigMgr->GetBoolDefault("PlayerAnnounce", true))
        {
            return;
        }

        switch (player->getClass())
        {
            case CLASS_WARLOCK:
                pClass = "Warlock";
                break;
            case CLASS_WARRIOR:
                pClass = "Warrior";
                break;
            case CLASS_MAGE:
                pClass = "Mage";
                break;
            case CLASS_SHAMAN:
                pClass = "Shaman";
                break;
            case CLASS_DEATH_KNIGHT:
                pClass = "Death Knight";
                break;
            case CLASS_DRUID:
                pClass = "Druid";
                break;
            case CLASS_HUNTER:
                pClass = "Hunter";
                break;
            case CLASS_PALADIN:
                pClass = "Paladin";
                break;
            case CLASS_ROGUE:
                pClass = "Rogue";
                break;
            case CLASS_PRIEST:
                pClass = "Priest";
                break;
        }

        LOG_WARN("module", "Player '{}' has logged in : Level '{}' : Class '{}' : IP '{}' : AccountID '{}'", playerName.c_str(), pLevel, pClass.c_str(), playerIP.c_str(), pAccountID);
    }
};

void AddWhoLoggedScripts()
{
    new WhoLoggedAnnounce();
}
