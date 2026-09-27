# FILE CREATED 27.09.2026
## An extension of readme for personal use and physics explanations every iteration.

# Log 27.09.26 - Pairwise Newtonian Gravity
 Started to create the main Newtonian gravity system.
 Using $F = G \frac{m_1 m_2}{r^2}$. First, I define displacement to get X and Y separation, and the specific direction.
 Then, I define the distance squared, and check if the dist is non zero to prevent the sim breaking.
 I next get define the regular distance and Normalise the direction vector by dividing the displacement by distance (The modulus of the displacement). Next, we calculate the acceleration.

($i$ is the Body from the outside loop, $j$ is the body from the inner loop
Newtonian gravity is 

$F = G \frac{m_1 m_2}{r^2}$
But that only tells us the size of the forces, not their direction. 
Newtons second law is:

$$
F = m_i a_i
$$

So we can rearrange to get 

$$
a_i = \frac{F}{m_i}
$$

If we substitute Gravity, we get

$$
a_i =
\frac{G \frac{m_i m_j}{r^2}}{m_i}
$$

Cancelling $m_i$ we get

$$
a_i = G \frac{m_j}{r^2}
$$
However we have yet to use any direction.
Include the unit direction vector from body $i$ to body $j$ so we can incorporate the direction of the vector:
$$
\hat{r}_{i \rightarrow j} =
\frac{\vec{r}_j - \vec{r}_i}{r}
$$

The final acceleration vector:

$$
\vec{a}_i =
\frac{G m_j}{r^2}
\hat{r}_{i \rightarrow j}
$$

(note to self, multiplying by unit vector doesnt change the gravity strength, as it = 1, just tells us the direction)
