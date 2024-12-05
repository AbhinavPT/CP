def solve_stone_columns(n, columns):
    # Check if there's at least one column with exactly 1 inscription
    assert any(col == 1 for col in columns), "At least one column must have exactly 1 inscription"
    
    # Track moves
    moves = []
    
    # Create a copy of columns to modify
    current = columns.copy()
    
    # Count occurrences of 0, 1, and 2 
    def count_distributions():
        return [current.count(0), current.count(1), current.count(2)]
    
    # Continue until columns are sorted
    while len(set(current)) > 1:
        # Find indices of different column values 
        zero_indices = [i for i in range(n) if current[i] == 0]
        one_indices = [i for i in range(n) if current[i] == 1]
        two_indices = [i for i in range(n) if current[i] == 2]
        
        # Prioritize moves that reduce the number of unique values
        if len(zero_indices) > 0 and len(one_indices) > 0:
            # Move from 1 to 0
            u, v = one_indices[0], zero_indices[0]
        elif len(one_indices) > 0 and len(two_indices) > 0:
            # Move from 2 to 1
            u, v = two_indices[0], one_indices[0]
        else:
            # If no obvious move, move to reduce max column
            max_val_indices = [i for i in range(n) if current[i] == max(current)]
            min_val_indices = [i for i in range(n) if current[i] == min(current)]
            u, v = max_val_indices[0], min_val_indices[0]
        
        # Perform the move
        if current[u] > current[v]:
            current[u] -= 1
            current[v] += 1
        else:
            current[v] -= 1
            current[u] += 1
        
        # Record the move (1-indexed)
        moves.append((u+1, v+1))
    
    return moves

def main():
    # Read number of test cases
    t = int(input())
    
    # Process each test case
    for _ in range(t):
        # Read number of columns
        n = int(input())
        
        # Read initial column inscriptions
        columns = list(map(int, input().split()))
        
        # Solve and get moves
        moves = solve_stone_columns(n, columns)
        
        # Output results
        print(len(moves))
        for u, v in moves:
            print(u, v)

if __name__ == "__main__":
    main()