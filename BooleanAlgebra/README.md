# Boolean Algebra Solver

This project is a simple solver for boolean algebra expressions with AND (`and`), OR (`or`), and NOT (`not`) gates. It handles up to 26 variables (`A` to `Z`) or direct boolean values (1 and 0)

## Features

- **Supported Gates:** AND (`and`), OR (`or`), NOT (`not`)
- **Variables:** Up to 26 variables (`A` to `Z`)
- **Direct Values:** Use `-1` followed by the expression to input boolean values directly
- **Examples:** Includes sample input/output files (`pub in`, `pub out`)

## Usage

- The first number indicates the number of variables, `N`
- The next `N` numbers represent the boolean values (1 for `true`, 0 for `false`) for each variable, in order (`A` to `Z`)
- Followed by the boolean expression
- - If the first number is `0`, the program will terminate

**Important:**

- **Gates** (AND, OR, NOT) **must be in lowercase** (`and` for AND, `or` for OR, `not` for NOT)
- **Variables** must be in uppercase (`A` to `Z`)
- The expression will not be evaluated correctly if these conventions are not followed

### Variables

- Format: `3 1 0 1 and(A, or(B, not(C)))`
- Variables: `[1, 0, 1]` (for `A=1`, `B=0`, `C=1`)
  
### Direct Boolean Values

- Format: `-1 and(1, or(0, not(1)))`

## Notes

- The solver **does not validate** the input expressions
- **Only** `and`, `or`, and `not` gates are supported
