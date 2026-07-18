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

## High-Level System Flow

```text
                    User
                      │
                      ▼
            ARES Mobile Application
                      │
                      ▼
              Authentication Service
                      │
                      ▼
                 FastAPI Backend
      ┌──────────────┼───────────────┐
      │              │               │
      ▼              ▼               ▼
 Risk Engine     Database        Maps Service
      │
      ▼
 AI Decision Support
      │
      ▼
 Emergency Response System
```
## Technology Stack

| Layer | Technology | Purpose |
|-------|------------|---------|
| Mobile Application | Flutter | Cross-platform mobile app |
| Backend | FastAPI | REST API and business logic |
| Programming Language | Python | Backend & AI development |
| Database | SQLite (initial) | Store application data |
| Database (future) | PostgreSQL | Production database |
| Version Control | Git & GitHub | Source code management |
| UI/UX Design | Figma | User interface design |
## Future Integrations

The following components are planned for future versions of ARES:

- AFAD Integration
- Earthquake Data API (Kandilli Observatory / AFAD)
- Weather API
- Google Maps API / OpenStreetMap
- Push Notification Service
- Arduino Sensor Network
- ESP32 IoT Devices
- Drone Monitoring System
- AI Prediction Engine
- Emergency Communication System