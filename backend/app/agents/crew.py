from ortools.sat.python import cp_model

class ProductionSolver:
    def __init__(self, scenes, locations):
        self.model = cp_model.CpModel()
        self.scenes = scenes
        self.horizon = 1440  # 24 hours in minutes
        
    def solve(self):
        intervals = []
        starts = {}
        
        for scene in self.scenes:
            # 1. Define Variables
            start = self.model.NewIntVar(0, self.horizon, f'start_{scene.id}')
            end = self.model.NewIntVar(0, self.horizon, f'end_{scene.id}')
            interval = self.model.NewIntervalVar(start, scene.duration_minutes, end, f'interval_{scene.id}')
            
            intervals.append(interval)
            starts[scene.id] = start

        # 2. Add Constraints: No two scenes can happen at once
        self.model.AddNoOverlap(intervals)

        # 3. Objective: Minimize Location Changes (The "Company Move" penalty)
        # (This requires creating transition variables - a great Phase 2 task!)
        
        solver = cp_model.CpSolver()
        status = solver.Solve(self.model)
        
        if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
            return {s_id: solver.Value(var) for s_id, var in starts.items()}
        return None