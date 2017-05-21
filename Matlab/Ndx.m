function Ndx = Ndx(n)
    % Include necessary libraries and include files
    addpath(genpath([pwd '/includes']));
    addpath(genpath([pwd '/lib']));
    
    % Compute quadrature nodes and weights
    [nodes,weights] = int_gauss_weights(n+1,0,1);
    for i=1:n+1
        for j=1:n+1
            Ndx(i,j)=eval_lagrange_deriv(j,nodes(i),nodes);
        end
    end
    
end