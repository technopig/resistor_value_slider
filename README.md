# resistor_value_slider

A Particle project named resistor_value_slider

## Setup the circuit
Only a photon, a breadboard, some resistor, and the `Blynk` app are needed.

Connect the resistor from `A0` to `A4`.

In the Blynk App, make the following:

| Widget | Pin | Note |
| ------ | --- | ---- |
| Vertical Slider | V1 | 0-255 |
| Button | V2 | |
| Value Display | V0 | 0-4095; `PUSH` reading rate |
| LED | V3 | I like green :white_check_mark: |

## Flash the code
Flash the code in `./src/resistor_value_slider.ino` to your photon. Substitute your own token in `char auth[]`.

## Curl the results
Use the following command to see the values stored in the Particle.variable() `resistVal` and `blynkVal`:

```
$ curl -G https://api.particle.io/v1/devices/<your_device_id>/blynkval -d access_token=<your_access_token> | python -m json.tool
```

You should receive a response like this:

```
{
    "cmd": "VarReturn",
    "coreInfo": {
        "connected": true,
        "deviceID": "<your_device_id>",
        "last_app": "",
        "last_handshake_at": "YYYY-MM-DDThh:mm:ss.tttZ",
        "last_heard": "YYYY-MM-DDThh:mm:ss.tttZ",
        "product_id": <some_int>
    },
    "name": "blynkval",
    "result": 0
}
```
