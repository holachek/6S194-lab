clear;          % Clear the workspace
close all;      % Close old figures

data_values = linspace(0, 100, 32);

% display 1
data10 = [10.800, 13.900, 13.800, 14.600, 15.300, 15.800, 14.700, 15.200, 15.900, 16.800, 18.500, 21.500, 22.800, 23.400, 24.000, 24.500, 25.400, 26.000, 26.700, 27.400, 28.000, 28.800, 29.700, 30.200, 30.900, 31.200, 28.200, 28.800, 29.400, 30.000, 30.700, 30.900];
data11 = [10.800, 15.200, 14.300, 14.600, 15.100, 15.600, 16.300, 17.900, 18.800, 21.500, 20.500, 21.300, 22.900, 23.000, 23.500, 22.000, 22.500, 23.000, 25.300, 25.700, 26.200, 26.700, 27.500, 27.500, 24.300, 24.500, 25.000, 25.400, 25.800, 26.100, 26.500, 27.800];
data12 = [10.800, 14.400, 15.300, 16.200, 16.900, 17.900, 19.300, 20.200, 20.800, 22.300, 23.600, 24.600, 25.700, 26.400, 26.900, 27.000, 28.000, 29.000, 29.700, 30.400, 30.000, 30.000, 31.100, 31.800, 32.600, 33.600, 34.200, 34.900, 35.800, 36.500, 37.200, 36.800];

% display 2
data20 = [16.700, 17.500, 17.500, 18.400, 22.000, 21.800, 24.400, 22.400, 22.500, 22.800, 23.500, 24.400, 25.100, 25.900, 26.600, 27.500, 28.200, 28.800, 29.700, 29.200, 29.800, 30.000, 30.400, 31.200, 31.700, 32.300, 32.900, 33.600, 34.200, 34.600, 35.100, 35.200];
data21 = [16.700, 18.600, 20.000, 20.800, 21.500, 21.900, 22.500, 23.500, 24.000, 24.500, 25.700, 26.500, 25.700, 25.200, 25.600, 26.700, 27.300, 27.700, 27.000, 27.200, 27.300, 27.900, 28.100, 28.400, 28.700, 29.200, 29.500, 29.800, 30.200, 30.800, 31.300, 31.200];
data22 = [16.700, 20.000, 21.300, 22.500, 23.400, 23.800, 25.100, 26.200, 27.500, 28.400, 29.200, 29.900, 29.400, 30.200, 31.100, 31.400, 32.100, 32.600, 33.200, 33.700, 34.500, 35.200, 35.900, 36.800, 37.500, 38.100, 38.700, 39.600, 40.300, 41.100, 41.500, 41.400];

% display 3
data30 = [14.100, 15.800, 16.400, 15.800, 16.400, 17.000, 17.700, 18.600, 19.200, 21.300, 24.800, 25.500, 26.100, 26.600, 27.300, 27.800, 28.400, 26.600, 26.900, 27.700, 28.500, 29.300, 29.700, 29.000, 29.400, 30.000, 30.800, 31.400, 31.900, 32.400, 33.200, 33.000];
data31 = [14.100, 16.300, 17.500, 18.000, 18.500, 19.100, 19.600, 20.500, 21.500, 23.000, 23.900, 24.400, 24.000, 23.400, 23.800, 23.700, 24.500, 23.800, 24.400, 24.900, 25.400, 25.900, 26.200, 26.600, 26.900, 27.100, 27.600, 28.000, 28.400, 28.800, 29.300, 28.700];
data32 = [14.100, 17.600, 18.700, 19.700, 20.700, 21.700, 22.500, 23.800, 24.800, 26.300, 27.200, 28.000, 28.700, 29.400, 29.800, 30.200, 31.300, 31.900, 32.100, 32.600, 32.600, 33.300, 34.000, 34.700, 35.500, 36.400, 37.300, 37.600, 38.300, 39.100, 39.700, 39.200];

figure('position', [100, 100, 500, 500])

plot( data_values, data10, 'o-r', 'LineWidth', 1.5 ); hold on;
plot( data_values, data11, 'o-g', 'LineWidth', 1.5 );
plot( data_values, data12, 'o-b', 'LineWidth', 1.5 );

plot( data_values, data20, 'o-r', 'LineWidth', 1.5 );
plot( data_values, data21, 'o-g', 'LineWidth', 1.5 );
plot( data_values, data22, 'o-b', 'LineWidth', 1.5 );

plot( data_values, data30, 'o-r', 'LineWidth', 1.5 );
plot( data_values, data31, 'o-g', 'LineWidth', 1.5 );
plot( data_values, data32, 'o-b', 'LineWidth', 1.5 );

xlabel( 'Intensity [%]', 'fontsize', 10 ); ylabel( 'Measured Current (mA)', 'fontsize', 10 );
title( '0.96" displays 1-3; calibration set to (0x91, 0x50, 0x7D)' );
grid on; ylim( [ 9, 45 ] ); xlim( [ 0, 100 ]); set( gca, 'fontsize', 14 );

print('oledpower_results_displayall_cal','-dpng','-r0') %2nd arg: -dpng for png, -depsc for eps