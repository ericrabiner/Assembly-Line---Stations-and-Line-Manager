# Assembly Line - Stations and Line Manager

An application written in C++ that fills customer orders from an inventory.

## Topics Covered
* design and code a composition
* work with vector and queue containers from the Standard Template Library
* work with class variables and functions
* parse a string into tokens
* report and handle exceptions
* move objects from one container to another

## Prerequisites
Install the Minimalist GNU for Windows

## Running the Application

Compile the source and header files.
```
g++ AssemblyLine.cpp CustomerOrder.cpp ItemSet.cpp LineManager.cpp project.cpp Station.cpp Utilities.cpp -std=c++17 -o assemblyline
```

Run the executable file.
```
./assemblyline.exe Inventory.txt CustomerOrders.txt AssemblyLine.txt
```

Example Output
```
Assembly Line Configuration and Order Processing
================================================

Items in Stock
--------------
CPU          [123456] Quantity 5   Description: Central Processing Unit
Memory       [654321] Quantity 10  Description: Basic Flash Memory
GPU          [456789] Quantity 2   Description: Graphics Processing Unit
SSD          [987654] Quantity 5   Description: Solid State Drive
Power Supply [147852] Quantity 20  Description: Basic AC Power Supply

For Manual Validation: Station 1
getName(): CPU
getSerialNumber(): 123456
getQuantity(): 5
getName(): CPU
getSerialNumber(): 123457
getQuantity(): 4

Customer Orders
---------------
Elliott C.  [Gaming PC]
            CPU
            Memory
            GPU
            GPU
            GPU
            SSD
            Power Supply
Chris S.    [Laptop]
            CPU
            Memory
            SSD
            Power Supply
Mary-Lynn M.[Desktop PC]
            CPU
            Memory
            Power Supply
Chris T.    [Micro Controller]
            GPU
            GPU
            Power Supply
            SSD

Assembly Line Configuration
---------------------------
CPU --> GPU
Memory --> SSD
GPU --> Memory
SSD --> END OF LINE
Power Supply --> CPU

For Manual Validation:
 Power Supply --> CPU
 CPU --> GPU
 GPU --> Memory
 Memory --> SSD
 SSD --> END OF LINE

Start Processing Customer Orders
--------------------------------
 Filled Elliott C. [Gaming PC][Power Supply][147852]
--> Elliott C. [Gaming PC] moved from Power Supply to CPU
 Filled Elliott C. [Gaming PC][CPU][123457]
 Filled Chris S. [Laptop][Power Supply][147853]
--> Elliott C. [Gaming PC] moved from CPU to GPU
--> Chris S. [Laptop] moved from Power Supply to CPU
 Filled Chris S. [Laptop][CPU][123458]
 Filled Elliott C. [Gaming PC][GPU][456789]
 Filled Elliott C. [Gaming PC][GPU][456790]
 Unable to fill Elliott C. [Gaming PC][GPU][0] out of stock
 Filled Mary-Lynn M. [Desktop PC][Power Supply][147854]
--> Chris S. [Laptop] moved from CPU to GPU
--> Elliott C. [Gaming PC] moved from GPU to Memory
--> Mary-Lynn M. [Desktop PC] moved from Power Supply to CPU
 Filled Mary-Lynn M. [Desktop PC][CPU][123459]
 Filled Elliott C. [Gaming PC][Memory][654321]
 Filled Chris T. [Micro Controller][Power Supply][147855]
--> Mary-Lynn M. [Desktop PC] moved from CPU to GPU
--> Elliott C. [Gaming PC] moved from Memory to SSD
--> Chris S. [Laptop] moved from GPU to Memory
--> Chris T. [Micro Controller] moved from Power Supply to CPU
 Filled Chris S. [Laptop][Memory][654322]
 Filled Elliott C. [Gaming PC][SSD][987654]
--> Chris T. [Micro Controller] moved from CPU to GPU
--> Chris S. [Laptop] moved from Memory to SSD
--> Mary-Lynn M. [Desktop PC] moved from GPU to Memory
--> Elliott C. [Gaming PC] moved from SSD to Incomplete Set
 Filled Mary-Lynn M. [Desktop PC][Memory][654323]
 Unable to fill Chris T. [Micro Controller][GPU][0] out of stock
 Unable to fill Chris T. [Micro Controller][GPU][0] out of stock
 Filled Chris S. [Laptop][SSD][987655]
--> Mary-Lynn M. [Desktop PC] moved from Memory to SSD
--> Chris T. [Micro Controller] moved from GPU to Memory
--> Chris S. [Laptop] moved from SSD to Completed Set
--> Chris T. [Micro Controller] moved from Memory to SSD
--> Mary-Lynn M. [Desktop PC] moved from SSD to Completed Set
 Filled Chris T. [Micro Controller][SSD][987656]
--> Chris T. [Micro Controller] moved from SSD to Incomplete Set

Results of Processing Customer Orders
-------------------------------------
COMPLETED ORDERS
Chris S.    [Laptop]
            [123458] CPU - FILLED
            [654322] Memory - FILLED
            [987655] SSD - FILLED
            [147853] Power Supply - FILLED
Mary-Lynn M.[Desktop PC]
            [123459] CPU - FILLED
            [654323] Memory - FILLED
            [147854] Power Supply - FILLED

INCOMPLETE ORDERS
Elliott C.  [Gaming PC]
            [123457] CPU - FILLED
            [654321] Memory - FILLED
            [456789] GPU - FILLED
            [456790] GPU - FILLED
            [0] GPU - MISSING
            [987654] SSD - FILLED
            [147852] Power Supply - FILLED
Chris T.    [Micro Controller]
            [0] GPU - MISSING
            [0] GPU - MISSING
            [147855] Power Supply - FILLED
            [987656] SSD - FILLED

Assembly Line Configuration and Processing Complete
```