package org.example;


import org.matsim.pt2matsim.run.CheckMappedSchedulePlausibility;
import org.matsim.pt2matsim.run.CreateDefaultPTMapperConfig;
import org.matsim.pt2matsim.run.Gtfs2TransitSchedule;
import org.matsim.pt2matsim.run.PublicTransitMapper;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.concurrent.ExecutionException;

public class Main {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        // Docs from https://github.com/matsim-org/pt2matsim

        // Create input files
        // Unmapped Transit Schedule
        String gtfsPath = "src/main/resources/inputs/gtfs.zip";
        String selectedDate = "20260101";
        String coordinateSystem = "EPSG:3857";
        String unmappedTransitSchedulePath = "src/main/resources/outputs/unmapped_transit_schedule.xml";
        String transitVehiclesPath = "src/main/resources/outputs/transit_vehicles.xml";
        Gtfs2TransitSchedule.main(new String[]{
                gtfsPath,
                selectedDate,
                coordinateSystem,
                unmappedTransitSchedulePath,
                transitVehiclesPath
        });

        // Map schedule to network
        // Public Transit Mapper
        String configPath = "src/main/resources/outputs/default_config.xml";

        if (Files.notExists(Path.of(configPath))) {
            CreateDefaultPTMapperConfig.main(new String[]{
                    configPath
            });
        }

        // Here will probably raise an error.
        // After creating the 'default_config.xml' file, modify the following parameters:
        // <param name="inputNetworkFile" value="src/main/resources/inputs/network.xml" />
        // <param name="inputScheduleFile" value="src/main/resources/outputs/unmapped_transit_schedule.xml" />
        // <param name="outputNetworkFile" value="src/main/resources/outputs/mapped_network.xml" />
        // <param name="outputScheduleFile" value="src/main/resources/outputs/mapped_transit_schedule.xml" />

        PublicTransitMapper.main(new String[]{
                configPath
        });

        // Check mapping result
        // Check Schedule Plausibility
        String mappedTransitSchedulePath = "src/main/resources/outputs/mapped_transit_schedule.xml";
        String mappedNetworkPath = "src/main/resources/outputs/mapped_network.xml";
        String plausibilityPath = "src/main/resources/outputs/plausibility";
        CheckMappedSchedulePlausibility.main(new String[]{
                mappedTransitSchedulePath,
                mappedNetworkPath,
                coordinateSystem,
                plausibilityPath
        });
    }
}
