#pragma once

#include <sdbusplus/bus.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/slot.hpp>

namespace sdbusplus
{

namespace server
{

namespace manager
{

/** @class manager
 *  @brief Provide a C++ holder for a sd-bus object manager.
 *
 *  Wraps sd_bus_add_object_manager so that an sd-bus owned object manager
 *  can be installed at a path and automatically removed when destructed.
 */
struct manager : private sdbusplus::bus::details::bus_friend
{
    /* Define all of the basic class operations:
     *     Not allowed:
     *         - Default constructor to avoid nullptrs.
     *         - Copy operations due to internal unique_ptr.
     *     Allowed:
     *         - Move operations.
     *         - Destructor.
     */
    manager() = delete;
    manager(const manager&) = delete;
    manager& operator=(const manager&) = delete;
    manager(manager&&) = default;
    manager& operator=(manager&&) = default;
    ~manager() = default;

    /** @brief Register an object manager at a path.
     *
     *  @param[in] bus - The bus to register on.
     *  @param[in] path - The path to register.
     */
    manager(sdbusplus::bus_t& bus, const char* path)
    {
        sd_bus_slot* slot = nullptr;
        sdbusplus::SdBusInterface* intf = bus.getInterface();

        intf->sd_bus_add_object_manager(get_busp(bus), &slot, path);

        _slot = std::move(slot);
    }

  private:
    slot_t _slot{};
};

} // namespace manager

using manager_t = manager::manager;

} // namespace server
} // namespace sdbusplus
