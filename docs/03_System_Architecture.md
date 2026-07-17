# System Architecture

## Overview

ARES is designed using a modular architecture.

Each module has a single responsibility and communicates with other modules.

---

## Modules

### 1. User Module

Responsible for:

- User login
- User registration
- Profile management

---

### 2. Disaster Module

Responsible for:

- Creating incidents
- Updating incidents
- Disaster information

---

### 3. Risk Engine

Responsible for:

- Risk calculation
- Threat level analysis
- Decision support

---

### 4. Resource Module

Responsible for:

- Ambulance management
- Fire department
- Rescue teams
- Equipment

---

### 5. Report Module

Responsible for:

- Statistics
- Reports
- Logs

---

### 6. Database Module

Responsible for:

- Store users
- Store incidents
- Store reports

---

## Architecture

User

↓

Application

↓

Business Logic

↓

Database