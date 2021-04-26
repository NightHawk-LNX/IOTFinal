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
MIIDWTCCAkGgAwIBAgIUPeRRd1bcYbXXyITnB4CzT/lC9gwwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIxMDMxNDE2Mzgz
M1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAO/ag98ECdhyaGjHsG/L
sawy6DB2Rtpab0l8gYvXfAQ53+1LT7b11voFq/ZXtS9dvuo9aCyhPD745/KxgIyZ
byDIiSJXgbnzZ7MVcRRyK0KcRc+vv6/5PebrkonulfSuCc1gUi43KtiYa6/VroBC
ALweyFJD5XW9jBQd6zGJX68BQxM4icruOv/J5P9g4f4N6XzRX2fKFMCNycd7fASq
Cfrl3DGXYstQYTsuYTw8X+nGPbIuQyARsMma/7UP8QSPqelkpFPYfyPT6MrOExo/
VyLSs+67B3rZCAs9C6Nz216m79UxeZ9HpiQSNdEq52BZjBvfZyrxAKpqCplWbcCL
pJ0CAwEAAaNgMF4wHwYDVR0jBBgwFoAUC+K9hazn7Ea3Kgy1xRYgacwUsOMwHQYD
VR0OBBYEFMOMb9TnfPxUr7U3fJ8YUDJkN+WVMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBo4OsyvT1PKAM19tltJ8isW1ds
7k/qs+6uQDGgivl11oTfXDrw9zi9charMe4fBak6ip3uVaQ4dHAClxCUpuKiK35S
Shz6axCZ6EhNOrjiuWxIH3ePTbauCgziYcwhobugHAVNuxz3Rn55q1WEQFZDUnVM
LG9g6XDJbFkijQxZhrHZwE9MyI+NmNUv0BG9MlPm5e8ejQOF6RdfyoX5pZXpNcFG
dMZT4vaC24Rz76aMgRdep6VD12pF93w1rqdSl9FMvtAvn6snn1cRuYBHmyrqleyP
8Mevnfn4poVxwHPS3gYRuPQPoqJXgoiSOYhw78XHQOJtDdeKPxo1nnEbln+U
-----END CERTIFICATE-----
)KEY";

// Private key -- copy-and-paste the contents of your
//  -private.pem.key file here
static const char AWS_CERT_PRIVATE[ ] = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA79qD3wQJ2HJoaMewb8uxrDLoMHZG2lpvSXyBi9d8BDnf7UtP
tvXW+gWr9le1L12+6j1oLKE8Pvjn8rGAjJlvIMiJIleBufNnsxVxFHIrQpxFz6+/
r/k95uuSie6V9K4JzWBSLjcq2Jhrr9WugEIAvB7IUkPldb2MFB3rMYlfrwFDEziJ
yu46/8nk/2Dh/g3pfNFfZ8oUwI3Jx3t8BKoJ+uXcMZdiy1BhOy5hPDxf6cY9si5D
IBGwyZr/tQ/xBI+p6WSkU9h/I9Poys4TGj9XItKz7rsHetkICz0Lo3PbXqbv1TF5
n0emJBI10SrnYFmMG99nKvEAqmoKmVZtwIuknQIDAQABAoIBAQDHuyFBHy3Lrkm/
pzoHfonvqVysrnGF9vThLur5tnExW7ha8/Hnm4RvIzX1p0fbr6cBjC0prQJsNf2A
ncs8SbC+jf+UN2ZxoH1kJaDKs9/OUi/YKLPpKBYiK10VuzXoUN0cxu7oSUxGnXZf
MANmDpBqFwAdcSitCTCSt+9YitrA8SFYAhcTkEX8rYOcxk6pJyUGbpWoUkFcr6Cw
QZxc8K90otlXN54GsmlQ6BaJ+4qFXWtGGmX+sdIJooGzwVoMFHuimQJoA7kCiimq
L3anFOD7mjXKBnYz9vMq+Jcs11kWAIouDimctyIfXGpXLhfSxbhKiVPFGyLhe4kT
5NTNOgmJAoGBAPvev9YgCeAbR+TthZ9TOmkWvMaTTxkcFZhq0LxOhug3EUOKKLy5
ZjtSkuXNgep9i1zAS3i1ykkJHWyCT31KQUTUcvfKUcM/lZtfpQLsccoNdW3hyMSU
EbdRxYwpBJhBnlEXpTlNX6wp6oA8uMEh0Z47fE324GoZv44KyNfq0E7bAoGBAPPJ
UznbP6aqIwlpofDGxnz8W/kVI88mViY8WtUIm3qt1pNyZIUcQrsGhOmJWBHgygqS
70b/8AUpXdu/A3K3mg9f2E90vFiMAwcLXgwkZ5Sa+Ua+ZEbZZRBzT6coCD3Ob2Cq
/TfygksGGt34YNqmwUstSCJDnZFfxCvR87ihrYfnAoGBAPCi8rmLRqQcrGWmIOIF
zGqW1KkMGKgu0tsaQm+GvxGhexcCKsWUhH3s+HgiDhuQ8tMczX54gNmiocAICBX2
GcG/EFB5tgBLAY6+pJLUgCrBDQ58hyp5JSv2Lj0o+0DUgIONicfjiqKcMXVvjjzH
KNR6lNqQIfx8uSzmVNklePu9AoGAbj6cEWzx4ufLwmTvo9fwSPNCkGib8gCvMslW
dkJXNWpJwBIaHQwDrVosXwQKPMN/+rop1NzG6T6kwEwoPgeDdvJr+rqathxS/iuI
00rfQJe4pOJSrKuBBahv2/LBj1m8imWo71UO0Oio27qH6jlA7kNC/KPBLM23A+4F
HniW5f8CgYBUSMPJzzJgulMCvjihSE4wM0W3pQYGpTAsEitSjJD0k7pfQdzBQGXe
/d5fu73OuT9tuG7Hz+ho0kFukbL1ZUKtq+9e7wO8pGakLk0vfwNBLWyGEOtnpLN/
do2D/hwLHQqIH956ogU393UPEQq0iCnGcHrAF/bdBJTQ+modb8RPcA==
-----END RSA PRIVATE KEY-----
)KEY";

// MQTT topics
static const char CMD_TOPIC[ ] = "nfc_lock/cmd";
static const char STATUS_TOPIC[ ] = "nfc_lock/status";

// AWS device name
static const char THINGNAME[] = "EE419_ESP";

// LEDs -- change these if you used different I/O pins
const int red = 12;
const int green = 13;
