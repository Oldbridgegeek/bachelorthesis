function find_structure(order)
    % Include necessary libraries and include files
    addpath(genpath([pwd '/includes']));
    addpath(genpath([pwd '/lib']));
    
    % Compute quadrature nodes and weights
    [nodes,weights] = int_gauss_weights(order+1,0,1);
    
    % Compute equidistant vertices for the elements
    vertices = equidistant_points(order);

    % Compute Mass Matrix as Tensor
    MASS_TENSOR = mass_tensor(order,weights,nodes,vertices);
    
    % Compute HOSVD
    [U,S,V]= hosvd_(MASS_TENSOR);
    
    MASS_TENSOR
    S
    




end