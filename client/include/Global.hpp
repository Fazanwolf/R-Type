#pragma once

#include <Skaldi.hpp>
#include <memory>

std::unique_ptr<sk::Client<sk::client::UDP>> gClt;
std::string gIP = "0.0.0.0";
std::string gPort = "5000";

