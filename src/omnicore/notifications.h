#ifndef OMNICORE_NOTIFICATIONS_H
#define OMNICORE_NOTIFICATIONS_H

#include <stdint.h>
#include <string>
#include <vector>

namespace mastercore
{
/** A structure for alert messages.
 */
struct AlertData
{
    //! Alert type
    uint16_t alert_type;
    //! Alert expiry
    uint32_t alert_expiry;
    //! Alert message
    std::string alert_message;
};

/** Determines whether the sender is an authorized source for Omni Core alerts. */
bool CheckAlertAuthorization(const std::string& sender);

/** Adds a new alert to the alerts vector. */
void AddAlert(uint16_t alertType, uint32_t alertExpiry, const std::string& alertMessage);

/** Alert string including meta data. */
std::vector<AlertData> GetOmniCoreAlerts();

/** Human readable alert messages. */
std::vector<std::string> GetOmniCoreAlertMessages();

/** Expires any alerts that need expiring. */
bool CheckExpiredAlerts(unsigned int curBlock, uint64_t curTime);

}

#endif // OMNICORE_NOTIFICATIONS_H
