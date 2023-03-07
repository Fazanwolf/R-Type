# R-Type Protocol

The protocol used by the R-Type game is a simple UDP protocol.
Binary data is sent and received in network byte order.

## 1. Authentication

* The client connects to the defined server port.
* The client sends a `?` to the client.
* The server responds with the `id`.

## 2. Player

### ID

The id of the player is set on the first 2 bits.

Possible values are:
  * Player 1: <u>00</u>00 0000
  * Player 2: <u>01</u>00 0000
  * Player 3: <u>10</u>00 0000
  * Player 4: <u>11</u>00 0000

### Movement

The movement of the player is set on 4 bits.
That set the bit corresponding to the direction.

**Example for Player 1:**
  * 0000 0000: No movement
  * 00<u>1</u>0 0000: Move up
  * 000<u>1</u> 0000: Move down
  * 0000 <u>1</u>000: Move left
  * 0000 0<u>1</u>00: Move right

### Shooting

The shooting of the player is set on the 7th bit.

**Example for Player 1:**
  * 0000 0000: No shooting
  * 0000 00<u>1</u>0: Shooting

### Collision

The collision of the player is set on the 8th bit.

**Example for Player 1:**
  * 0000 0000: No collision
  * 0000 000<u>1</u>: Collision

