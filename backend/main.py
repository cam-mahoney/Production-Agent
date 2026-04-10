import uvicorn
from fastapi import FastAPI, HTTPException
from typing import List

# Import your custom modules
from app.models.schemas import Scene, ActorAvailability
from app.solver.scheduler import ProductionSolver
from app.agents.crew import ProductionCrew

app = FastAPI(title="FilmTech API", description="AI-Driven Production Logistics")

@app.get("/")
async def root():
    return {"status": "Production Office is Online", "version": "1.0.0"}

@app.post("/schedule/optimize")
async def create_schedule(scenes: List[Scene]):
    """
    Takes a list of scenes (extracted by Agents) and returns 
    the mathematically optimal start times.
    """
    try:
        # Initialize the Google OR-Tools Solver
        solver = ProductionSolver(scenes=scenes, locations=[])
        
        # Run the Constraint Satisfaction math
        schedule_results = solver.solve()
        
        if not schedule_results:
            raise HTTPException(status_code=400, detail="No feasible schedule found with these constraints.")
            
        return {
            "message": "Optimal schedule generated successfully",
            "schedule": schedule_results
        }
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

@app.post("/script/breakdown")
async def breakdown_script(script_text: str):
    """
    Triggers the CrewAI Agent team to analyze the script prose.
    """
    crew_manager = ProductionCrew()
    
    # Define the task for our AI Agents
    task = crew_manager.breakdown_task(script_text)
    
    # Kick off the Agentic workflow
    # Note: In a real app, this would be an async background task
    crew = Crew(
        agents=[crew_manager.coordinator],
        tasks=[task],
        verbose=True
    )
    
    result = crew.kickoff()
    return {"analysis": result}

if __name__ == "__main__":
    # Standard dev server entry point
    uvicorn.run("main:app", host="0.0.0.0", port=8000, reload=True)