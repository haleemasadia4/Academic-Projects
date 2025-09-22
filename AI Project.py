def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)
def check_winner(board, player):
    for i in range(3):
        if (board[i][0] == board[i][1] == board[i][2] == player) or \
           (board[0][i] == board[1][i] == board[2][i] == player):
            return True
    if (board[0][0] == board[1][1] == board[2][2] == player) or \
       (board[0][2] == board[1][1] == board[2][0] == player):
        return True
    return False
def is_full(board):
    for row in board:
        for cell in row:
            if cell == " ":
                return False
    return True
def minimax(board, depth, is_maximizing, alpha, beta):
    if check_winner(board, "O"):
        return 10 - depth
    if check_winner(board, "X"):
        return depth - 10
    if is_full(board):
        return 0
    if is_maximizing:
        max_eval = -float('inf')
        for i in range(3):
            for j in range(3):
                if board[i][j] == " ":
                    board[i][j] = "O"
                    eval = minimax(board, depth + 1, False, alpha, beta)
                    board[i][j] = " "
                    max_eval = max(max_eval, eval)
                    alpha = max(alpha, eval)
                    if beta <= alpha:
                        break
        return max_eval
    else:
        min_eval = float('inf')
        for i in range(3):
            for j in range(3):
                if board[i][j] == " ":
                    board[i][j] = "X"
                    eval = minimax(board, depth + 1, True, alpha, beta)
                    board[i][j] = " "
                    min_eval = min(min_eval, eval)
                    beta = min(beta, eval)
                    if beta <= alpha:
                        break
        return min_eval
def ai_move(board):
    best_score = -float('inf')
    best_move = None
    for i in range(3):
        for j in range(3):
            if board[i][j] == " ":
                board[i][j] = "O"
                score = minimax(board, 0, False, -float('inf'), float('inf'))
                board[i][j] = " "
                if score > best_score:
                    best_score = score
                    best_move = (i, j)
    if best_move:
        board[best_move[0]][best_move[1]] = "O"
def tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    print("Welcome to Tic-Tac-Toe!")
    print("You are 'X' and AI is 'O'.")
    print_board(board)
    while True:
        try:
            move = int(input("Enter your move (1-9): ")) - 1
            row = move // 3
            col = move % 3
            if board[row][col] != " ":
                print("Invalid move! Try again.")
                continue
        except (ValueError, IndexError):
            print("Invalid input! Enter a number between 1 and 9.")
            continue
        board[row][col] = "X"
        print_board(board)
        if check_winner(board, "X"):
            print("Congratulations! You win!")
            break
        if is_full(board):
            print("It's a draw!")
            break
        print("AI is making a move...")
        ai_move(board)
        print_board(board)
        if check_winner(board, "O"):
            print("AI wins! Better luck next time.")
            break
        if is_full(board):
            print("It's a draw!")
            break
if __name__ == "__main__":
    tic_tac_toe()

