from pydantic import BaseModel
from typing import List, Optional

class Scene(BaseModel):
    id: int
    title: str
    location_id: str
    duration_minutes: int
    required_actors: List[str]
    is_interior: bool

class ActorAvailability(BaseModel):
    actor_name: str
    available_windows: List[dict] # e.g., {"start": 0, "end": 480}