function N = N(n)    
    % Include necessary libraries and include files
    addpath(genpath([pwd '/includes']));
    addpath(genpath([pwd '/lib']));
    
    % Compute quadrature nodes and weights
    [nodes,weights] = int_gauss_weights(n+1,0,1);
    for i=1:n+1
        for j=1:n+1
            N(i,j)=eval_lagrange(j,nodes(i),nodes);
        end
    end
    
end