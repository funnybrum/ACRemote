# ACRemote

A project helping you to turn your home a bit more smarter. Combines a remote and power meter that are exposed trough WEB server. The goal is to measure the power consumption of an air conditioner and provide WEB interface for subset of the supported commands by it.

This is implemented in quite generic approach. The IR remote part requires the full IR command as JSON. This means that the same hardware device will be able to control different air conditioners, but the device doing the 'smart home' stuff (i.e. the hub) should have a list of all commands that should be executed by the device.

# Hardware
The hardware is pretty simple.

The IR remote controlling part is realized with just one IR LED, transistor and few resistors.

The power meter is just a ACS712 current sensor module.

Pictures and schematics will be added as last part of the project.