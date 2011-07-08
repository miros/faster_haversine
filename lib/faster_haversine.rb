require File.join(File.dirname(__FILE__), '../ext/faster_haversine/faster_haversine.so')

module FasterHaversine

  # Calculates distance between two points
  #
  # @param [Float] lat1
  # @param [Float] lng1
  # @param [Float] lat2
  # @param [Float] lng2
  # @return [Float] distance
  def self.distance(lat1, lng1, lat2, lng2)
    haversine_distance(lat1, lng1, lat2, lng2)
  end

end