#pragma once

// Modify the following to be your login and password for the VMI-Sentinel and Barracks-Secure wifi
const char* identity = "housandnj21"; 
const char* password = "This is so pointless";

// Edit the following for the network you are using
const char* ssid = "VMI-Sentinel";

// AWS custom endpoint -- edit to use your endpoint
static const char AWS_ENDPOINT[ ] = "a32a8ixqt216yg-ats.iot.us-east-2.amazonaws.com";

// Amazon Root CA 1 -- you can use this key as-is
static const char AWS_CERT_CA[ ] = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)KEY";

// Device certificate -- copy-and-paste the contents of your
//  -certificate.pem.crt file here
static const char AWS_CERT_DEVICE[ ] = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAJtKOthRDiEDx5wRDC10QGwYQnFDMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMTA0MjcwMTMx
NTFaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDCX0mcjcj6h1TFhyL+
eD5JTnmBSMYq2lNjSRv1hsNjDj9WDkPCpNAJGhTvjYIf/HVaBiUnseppGxV3yiFe
plfxBfuRIUnMVTuO78glNYobDwaVgdwUA6JDkBqzhNOWUJ5epxb+oLneBJTnzOml
p8TQqlL3z5acdflUR2XsOLzBtZvhVWRtUYPCtqXUhz++PxJfFu/AcBNa9h6JYioy
TC5UZy83vjeowXlhFA1l1jNaK5Y7Yly5cBFwqiT2bxauH3Aj27J1V6A7/NCiCZSQ
d/8VacSxBUzYArnguZmK6VRu4t60A1dBmvb1ecggLs3I5okpRiHf52G5cMlG/53/
CKuVAgMBAAGjYDBeMB8GA1UdIwQYMBaAFP2ac6qgl3MYh6joP3yBMbpgZZS+MB0G
A1UdDgQWBBQwCPuuaSWWnmjtiQ0Zk7mMvrnhYzAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAshDeoeQSWS1bMa6Xtkx+OOn4
NH9Maeu4yy9tQsdlZnRVkIfpHMWRgjZq5Zy8V0VDYiYQ6j66ecY03Pj2IR1XUWUm
8ZWPyGN4rOtgIIAN1r/0H1+l2m9IXh10zJSvO7bgYixfQlbshZWm9WAEvQf68qIG
88Aum3ol96Rau+8hBn5HwyePutGpjN/3i3Ukd3+n2J4xdjjB7dFA7SJnuKJY0dSb
blyF9csiLT6pxBWQJMWWNRhb1KvtUff1+TuNbKwgw4yjtltsz3uKyk1jlplOsvB8
yBtj40MBllasXLbXC8VtM02moqBEIFm/zq3su6GR8ujaE7c0QnVoxVYoWsbwiw==
-----END CERTIFICATE-----
)KEY";

// Private key -- copy-and-paste the contents of your
//  -private.pem.key file here
static const char AWS_CERT_PRIVATE[ ] = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAwl9JnI3I+odUxYci/ng+SU55gUjGKtpTY0kb9YbDYw4/Vg5D
wqTQCRoU742CH/x1WgYlJ7HqaRsVd8ohXqZX8QX7kSFJzFU7ju/IJTWKGw8GlYHc
FAOiQ5Aas4TTllCeXqcW/qC53gSU58zppafE0KpS98+WnHX5VEdl7Di8wbWb4VVk
bVGDwral1Ic/vj8SXxbvwHATWvYeiWIqMkwuVGcvN743qMF5YRQNZdYzWiuWO2Jc
uXARcKok9m8Wrh9wI9uydVegO/zQogmUkHf/FWnEsQVM2AK54LmZiulUbuLetANX
QZr29XnIIC7NyOaJKUYh3+dhuXDJRv+d/wirlQIDAQABAoIBADndEBbxBqG+Y/gh
0MMcnL5KBFX+ii/7qtNl0lL3eXclqKk/ueBaHCx5fT4LTG+lQnI4XhtBFd2QWIW+
wMxijM+NzmRYGpYf0YktzNF27NQ9VuJvNEspAcdHQQusQSkAewUGjQvkYTC9AG85
S10rYqYT7nsja1zMqhry3l7CTT8FAqRnU5Cw6tiZEcMzKqpZF3wSLVDQZoty7r5b
TIaJVogq5QT4g8WIseZZEEtp6qFuQSzZWd4ieIrqMTbaVoO4H0GpOO8LHtb5q0Dh
H9iqw13qSllt+mgpzdopUsVFDf7atBVmVDKykS3+B+ibvFAsEMxx+s8gzsWtXS7z
flW84wECgYEA6Eun5FayO1Wu/Fz6EYJn8mdJTP/ZdgkssY4nEXY2CUsWUb9mvQh8
T7YhTa2k887rF5l9QUtsgBdmuy1KBkGGobxq21/PExcXHk/f9W60KQFuTjvEiEiN
YsNSWozk//CUOJBeNbZ8Wd85IqYSmv9JxaY0tEJ6AHlY+5DVdOwryXUCgYEA1jTy
VgVLpxcwujuS+2hTSFB7jkvI4NF97BXXNFF2ktEwkhoiuI8MdYx3r/Dz/yBGJ7o9
0z38IdL+p63bpQmMMmR+yyqUXLmBIW0pYDrzQb52A4s2zDH6awihNFsnyz5y7kDm
iKN2h3SUfnIBeJGa3IqCyAHj66zybBwiy6iq9aECgYEAiZC8RZoeBMtyTFtXcGUU
39XQ7/uYMbGvORshAdNKnuhLuG+sDQhobeBDCrhptkT0rk4kgjWDdLvnB7QDYX8O
ltt5QJ8Vh42mEDpnO/aqVJpXU5dLhRXKPRHExIEp4HP9ox3D3PVL4QEz2dQVspq6
eoU6MwInM/6o9pnH/20ZZT0CgYBBqR8zoRHsmR41p/dJG1SUER+eobpkt7KqwJMk
FWiMXpVN47cK7cZ67eDuTKTuan02xk8XRqPX1m57Bb8TWtbfx5BaRKYPuklL7sNF
HSzd1T0lnvHgK93AG3gWrW6ITY87WyePcNPvd5vhGp86zx8yRT8LghDUeEIjQ4ii
9wPYoQKBgQC4p3yRA9WGxbB2C7AjOPxCq/h1nUr4QOQtpH8Q/oxdJmzevoAePNfD
cgTw7RFjHNYgu85BQz7VigRiO5zYT5Xf0HU1ITKiuAS5FWjYAW50V2YogsbdjvCo
8dVoFIH03I1CHSKS1sW7d04mkfRtnfIVj4GuK6ovxqaZACwutrULPQ==
-----END RSA PRIVATE KEY-----
)KEY";

// MQTT topics
static const char CMD_TOPIC[ ] = "Motor/cmd";
static const char STATUS_TOPIC[ ] = "Motor/status";

// AWS device name
static const char THINGNAME[] = "EE419_ESP";

// LEDs -- change these if you used different I/O pins
const int forward = 12;
const int reverse = 13;
