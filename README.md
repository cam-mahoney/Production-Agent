# Production-Agent

FilmTech: The Agentic Production Office
A Multi-Agent System (MAS) designed to automate the logistical heavy lifting of independent filmmaking. This project bridges the gap between Software Engineering and Film Production by combining LLM-powered script analysis with industrial-grade constraint solving.

Core Functionality
Agentic Script Breakdown: A team of CrewAI agents (Coordinator, Scout, and Accountant) parses screenplays to extract props, cast requirements, and equipment lists.

Logistics Engine: Utilizes Google OR-Tools (CP-SAT) to solve complex scheduling puzzles, optimizing for minimal "Company Moves" while respecting actor availability and 12-hour turnarounds.

Production Suite: Automated generation of daily call sheets and "Crafty" logic that cross-references crew dietary restrictions with budget constraints.
