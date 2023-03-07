#ifndef SKALDI_PLAYER_PROTOCOL_HPP
#define SKALDI_PLAYER_PROTOCOL_HPP

#include "protocol/BinaryManipulation.hpp"

class PlayerProtocol : public sk::proto::BinaryManipulation {
public:
    PlayerProtocol() {
        _packet = bytes("00000000");
    }
    ~PlayerProtocol() = default;

    enum PlayerActionEnum {
        ID1 = 0,
        ID2 = 1,
        UP = 2,
        DOWN = 3,
        LEFT = 4,
        RIGHT = 5,
        SHOOT = 6,
        COLLIDE = 7,
    };

    enum class PlayerIDEnum {
        PLAYER1 = 0,
        PLAYER2 = 1,
        PLAYER3 = 2,
        PLAYER4 = 3,
        ME = 4,
        NONE = 5,
    };

    static const std::string playerIdToString(PlayerIDEnum id)
    {
        switch (id) {
            case PlayerIDEnum::PLAYER1:
                return "00";
            case PlayerIDEnum::PLAYER2:
                return "01";
            case PlayerIDEnum::PLAYER3:
                return "10";
            case PlayerIDEnum::PLAYER4:
                return "11";
            default:
                return "";
        }
    }

    bytes setPlayerId(PlayerIDEnum id)
    {
        const std::string idStr = playerIdToString(id);

        _packet = setBinaryBit(_packet, ID1, idStr.c_str()[0]);
        _packet = setBinaryBit(_packet, ID2, idStr.c_str()[1]);

        return _packet;
    }

    bytes setPlayerId(int id)
    {
        const std::string idStr = playerIdToString(static_cast<PlayerIDEnum>(id));

        _packet = setBinaryBit(_packet, ID1, idStr.c_str()[0]);
        _packet = setBinaryBit(_packet, ID2, idStr.c_str()[1]);

        return _packet;
    }

    bytes setPlayerMove(PlayerActionEnum action, bool value)
    {
        if (action == UP || action == DOWN || action == LEFT || action != RIGHT)
            _packet = setBinaryBit(_packet, action, value);
        return _packet;
    }

    bytes setPlayerShoot(bool value)
    {
        _packet = setBinaryBit(_packet, SHOOT, value);
        return _packet;
    }

    bytes setPlayerCollide(bool value)
    {
        _packet = setBinaryBit(_packet, COLLIDE, value);
        return _packet;
    }

    void printPacket()
    {
        std::cout << "Binary: " << _packet << " ASCII: " << binaryToASCII(_packet) << std::endl;
    }

    bytes clearPacket()
    {
        for (int i = 2; i < 8; i++)
            _packet = setBinaryBit(_packet, i, false);
        return _packet;
    }

protected:
private:
    bytes _packet;
};


#endif //SKALDI_PLAYER_PROTOCOL_HPP