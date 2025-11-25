---
applyTo: "iat_*/**/*.c"
---

# Agent Instructions: DayZ Enforce Script (Enfusion) — Conventions & Best Practices

**Audience:** An AI/code-writing agent producing DayZ (Enfusion) Enforce Script.
**Scope:** Favor DayZ Enforce specifics. Borrow Reforger conventions only where they generalize cleanly. Cite DayZ wiki as primary source; use Reforger “Conventions/Best Practices” to shape style (namespacing/tagging, documentation, maintainability). ([community.bistudio.com][1])

---

## 1) Language Fundamentals (what the agent must assume and use)

-   **OOP & Lifecycle**

    -   Classes, inheritance, constructors `void ClassName(args)`, destructors `void ~ClassName()`. Prefer RAII-style cleanup; rely on Enforce ARC (automatic ref-counted destruction at scope end) where safe; call `delete` when ownership is explicit. ([community.bistudio.com][1])

-   **Visibility & Modding**

    -   Use `modded class` to extend engine or game classes, do not directly edit base sources. Keep overrides minimal and documented. (DayZ/Enfusion pattern; consistent with BI guidance.) ([community.bistudio.com][1])

-   **Keywords you’ll see**

    -   `static`, `const`, `proto` (native/prototyped), `override`, `super`, `private/protected`. Use `const` for compile-time constants and `static const` for shared constants. Prefer `enum` for grouped integral constants. ([community.bistudio.com][1])

-   **Core types & containers**

    -   Primitives: `int`, `float`, `bool`, `string`; math `vector`; meta `typename`.
    -   Collections: `array<T>`, `map<TKey,TValue>`. Pre-size when possible; reuse arrays in hot paths. ([community.bistudio.com][1])

-   **Memory patterns**

    -   Prefer engine-managed lifetimes; avoid raw `new` in tight loops. If you allocate, define clear ownership and `delete` appropriately. Keep temporary objects on-stack and leverage ARC where applicable. ([community.bistudio.com][1])

---

## 2) Project/Layout (DayZ module order & availability)

-   Put script sources into the standard DayZ module tiers so dependencies load in order. Typical layers include **Core → Game/Gameplay → World → Mission**; place APIs in the earliest viable tier, and gameplay code later (e.g., Mission). Do **not** cross-call forward into not-yet-loaded tiers. ([community.bistudio.com][1])

---

## 3) Naming & Code Style (DayZ-first; Reforger rules where universal)

-   **Global collision avoidance (Tagging)**

    -   Prefix **all** global classes, enums, and free functions with a unique short **Tag** for your mod to avoid collisions (e.g., `IAT_` for "ItsATreee"). BI uses prefixes in their own code; adopt the same practice. ([community.bistudio.com][2])

-   **Class & method casing**

    -   **Classes/Enums:** `PascalCase` (`IAT_SmeltingForge`).
    -   **Methods/Functions:** `PascalCase` or `UpperCamelCase` consistent with engine style (`ProcessInput`, `OnInit`).
    -   **Fields:** `m_` prefix for instance members (`m_Temperature`), `s_` for statics (`s_Registry`), and `g_` sparingly for truly global singletons. (Common DayZ convention; mirrors BI patterns.) ([community.bistudio.com][1])

-   **Constants**

    -   `static const int IAT_MaxFuel = 100;` Place alongside the type they belong to; prefer enums for sets. ([community.bistudio.com][1])

-   **Events/overrides**

    -   Keep `OnInit/OnUpdate/EEInit/EEDelete` overrides lean; delegate work to private helpers. Document side effects. (General BI guidance on maintainability.) ([community.bistudio.com][3])

-   **Comments & docs**

    -   Use short **line comments** for intent and **Doxygen-style** for public APIs (`/** .. */`, `///`) so tools can extract docs. Keep comments current. ([community.bistudio.com][2])

---

## 4) Modding Patterns for DayZ

-   **Subclass, don’t fork.** Prefer `modded class` to extend/augment vanilla behavior; minimize copy-paste of base classes. ([community.bistudio.com][1])
-   **Config & script alignment.** Keep class names and config (types, proxies, animation sources) in sync with script tags/prefixes to avoid collisions across mods. (Community-safe practice reflecting BI’s collision-avoidance guidance.) ([community.bistudio.com][2])
-   **RPC & multiplayer**

    -   Keep networked logic authoritative (server-side), send minimal payloads; validate all client inputs.
    -   Throttle or batch RPCs from frequent events (UI ticks, item updates). (General Enfusion/BI best-practice.) ([community.bistudio.com][3])

-   **Logging & diagnostics**

    -   Use `Print` for info, reserve error-level outputs for actionable faults; add mod tag to messages (e.g., `[IAT] Forge over temp: 1050C`). Remove verbose debug logs in release builds. ([community.bistudio.com][1])

-   **Performance hygiene**

    -   Avoid allocations in `OnUpdate`/per-frame; reuse arrays/structs, cache lookups, precompute hashes.
    -   Keep scripts data-oriented for hot paths; prefer constant-time checks; short-circuit early. (BI best-practices ethos.) ([community.bistudio.com][3])

---

## 5) API Surface & Safety

-   **Public API shape**

    -   Keep public methods minimal; expose intent-driven verbs (`StartSmelt`, `AbortSmelt`) and hide mechanical helpers (`CalcYieldWindow_`).
    -   Validate at boundaries: null checks, range checks, server/authority checks before state changes. ([community.bistudio.com][3])

-   **Immutability & contracts**

    -   Prefer `const` parameters where possible; document pre/post-conditions in comments. Use enums instead of magic numbers. ([community.bistudio.com][1])

---

## 6) Files, Organization & Review

-   **One class per file** (exceptions: small DTOs/params). File name = class name (with tag prefix).
-   **Group by feature** under your mod root (`Scripts/3_Game/IAT/Smelting/`), mirroring DayZ load tiers.
-   **Code reviews**: enforce tag usage, member prefixes, error handling, RPC throttling, and docs presence. (Generalized from BI Reforger guidance.) ([community.bistudio.com][2])

---

## 7) Example Skeleton (DayZ-flavored)

```cpp
// File: Scripts/4_World/IAT/Smelting/IAT_SmeltingForge.c
modded class IAT_SmeltingForge : SomeDayZBaseForge
{
    static const int IAT_MaxFuel = 100;

    protected float m_Temperature;
    protected ref array<int> m_FuelInventory = new array<int>;

    void IAT_SmeltingForge()
    {
        m_Temperature = 0;
    }

    void ~IAT_SmeltingForge()
    {
        // explicit cleanup only if you own the object/resource
        // arrays are ref-counted; avoid manual delete unless you own raw pointers
    }

    // Public API
    void StartSmelt(IAT_SmeltingRecipe recipe)
    {
        if (!GetGame().IsServer()) return; // authority check
        if (!recipe) { Print("[IAT] StartSmelt: null recipe"); return; }

        if (!HasFuel()) { Print("[IAT] No fuel"); return; }
        m_Temperature = ComputeStartTemp(recipe);
    }

    protected bool HasFuel()
    {
        return m_FuelInventory && m_FuelInventory.Count() > 0;
    }

    protected float ComputeStartTemp(IAT_SmeltingRecipe recipe)
    {
        // keep pure, side-effect free; easy to unit test
        return recipe.MinTemp();
    }
}
```

(Shows: tag prefix, member prefixes, ctor/dtor, authority check, minimal public API, helper segregation.) ([community.bistudio.com][1])

---

## 8) Documentation Footer (for generated files)

-   Add a brief header to every generated file:

    -   Mod tag, purpose, owner, load tier (`4_World`, etc.), and risks (RPC/network, persistence, AI).
    -   Link out to internal docs/changelogs.

---

## 9) When borrowing Reforger guidance

-   Safely adopt **Tag prefixes**, **documentation style**, **maintainability rules**, and **conflict-avoidance**—these are engine-agnostic and reduce mod conflicts in DayZ. Do **not** import Reforger-only APIs or patterns that don’t exist in DayZ. ([community.bistudio.com][2])

---

## Canonical References (for this agent)

-   **DayZ: Enforce Script Syntax** — language semantics, OOP, examples, and engine expectations. Use as your first stop. ([community.bistudio.com][1])
-   **Arma Reforger: Scripting Conventions & Best Practices** — mine for general coding standards (tagging, doc, maintainability) that _also_ reduce DayZ mod conflicts. ([community.bistudio.com][2])
-   **Enforce Doxygen mirrors** (for quick lookups when the main wiki is slow): container + utilities, arrays, maps, debug helpers. Use as supplemental reference only. ([dayz-scripts.yadz.app][4])

---

### Short checklist (apply on every PR/auto-generated file)

-   [ ] Class/file names use your mod **Tag**; no globals without tag. ([community.bistudio.com][2])
-   [ ] Members prefixed `m_` (and `s_` for statics). Public API minimal & documented. ([community.bistudio.com][3])
-   [ ] Lifecycle correct (ctors/dtors), ARC respected; no leaks; no per-frame allocations. ([community.bistudio.com][1])
-   [ ] Load-tier placement correct (Core/Game/World/Mission). ([community.bistudio.com][1])
-   [ ] Authority checks for networked actions; client inputs validated. ([community.bistudio.com][3])
-   [ ] Logs are tagged; no noisy debug in release. ([community.bistudio.com][1])

---
