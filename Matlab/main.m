function main(order)
    % Include necessary libraries and include files
    addpath(genpath([pwd '/includes']));
    addpath(genpath([pwd '/lib']));

    [nodes,weights] = int_gauss_weights(order+1,0,1);
    vertices = equidistant_points(order);

    % Compute Mass Matrix as Tensor
    MASS_TENSOR = mass_tensor(order,weights,nodes,vertices);
    
    % Compute HOSVD
    [U, S, V] = hosvd_(MASS_TENSOR);
    
    % Compute the inverse of the Mass Tensor
    %MASS_TENSOR_INVERSE = hosvd_inverse(S,V);
 
    
    % Check if its really the pseudo inverse
    MASS_MATRIX = tensor_to_matrix(MASS_TENSOR,order);
    %MASS_MATRIX_PSEUDOINVERSE = tensor_to_matrix(MASS_TENSOR_INVERSE,order);
    test = moore_penrose_prop(MASS_MATRIX,pinv(MASS_MATRIX))
    
    
    
    
    % Solve linear system
    %A = MASS_MATRIX;
    %M = MASS_MATRIX_PSEUDOINVERSE;
    %maxit = 10000;
    %tol = 10^-10;
    %restart = 1;
    %b= rand((order+1)^2,1);
    %pcg(A,b,tol,maxit,M)
    %gmres(A,b,restart,tol,maxit,M);    
end