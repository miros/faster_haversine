# encoding: utf-8

require 'rubygems'
require 'bundler'
begin
  Bundler.setup(:default, :development)
rescue Bundler::BundlerError => e
  $stderr.puts e.message
  $stderr.puts "Run `bundle install` to install missing gems"
  exit e.status_code
end
require 'rake'

require 'jeweler'
Jeweler::Tasks.new do |gem|
  # gem is a Gem::Specification... see http://docs.rubygems.org/read/chapter/20 for more options
  gem.name = "faster_haversine"
  gem.homepage = "http://github.com/miros/faster_haversine"
  gem.license = "MIT"
  gem.summary = %Q{Haversine great-circle distance formula}
  gem.description = %Q{Haversine great-circle distance formula implemented as C extension}
  gem.email = "mirosm@mirosm.ru"
  gem.authors = ["miros"]
  gem.extensions = ["ext/faster_haversine/extconf.rb"]
  gem.files.include 'ext/faster_haversine/faster_haversine.so'
  gem.files.include 'ext/faster_haversine/faster_haversine.o'
  # dependencies defined in Gemfile
end
Jeweler::RubygemsDotOrgTasks.new

require 'rspec/core'
require 'rspec/core/rake_task'
RSpec::Core::RakeTask.new(:spec) do |spec|
  spec.pattern = FileList['spec/**/*_spec.rb']
end

RSpec::Core::RakeTask.new(:rcov) do |spec|
  spec.pattern = 'spec/**/*_spec.rb'
  spec.rcov = true
end

task :default => :spec

require 'yard'
YARD::Rake::YardocTask.new